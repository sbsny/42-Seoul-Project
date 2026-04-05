#include "../../incl/minishell.h"

void	update_child_exit_code(t_data *shell_state)
{
	int status;

	status = 0;
	waitpid(shell_state->pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
}

static int	spawn_pipeline_child(t_data *shell_state)
{
	signal(SIGINT, SIG_IGN);
	shell_state->pid = fork();
	if (shell_state->pid < 0)
	{
		perror(NULL);
		free_cmd_and_path(shell_state);
		return (-1);
	}
	return (0);
}

static int	open_pipeline_pipe(t_data *shell_state)
{
	if (pipe(shell_state->pipe) < 0)
	{
		perror(NULL);
		free_cmd_and_path(shell_state);
		return (-1);
	}
	return (0);
}

void	run_pipeline_stage(t_data *shell_state)
{
	int builtin;

	if (open_pipeline_pipe(shell_state) < 0)
		return ;
	if (shell_state->exec->no_cmd == true || shell_state->parse_error == true)
	{
		forward_pipe_input(shell_state);
		return ;
	}
	builtin = identify_builtin_cmd(shell_state);
	if (builtin >= 0)
		run_stage_builtin(shell_state, builtin);
	else
	{
		if (spawn_pipeline_child(shell_state) < 0)
			return ;
		sleep(10);
		if (shell_state->pid == 0)
		{
			configure_signal_mode(SIGNAL_MODE_CHILD);
			wire_stage_redirection(shell_state);
			run_external_command(shell_state);
		}
		forward_pipe_input(shell_state);
	}
}

void	run_pipeline_last_stage(t_data *shell_state)
{
	int builtin;

	if (shell_state->exec->no_cmd == true || shell_state->parse_error == true)
	{
		restore_stdio_fds(shell_state);
		if (shell_state->parse_error == true)
			g_exit_code = EXIT_FAILURE;
		return;
	}
	builtin = identify_builtin_cmd(shell_state);
	if (builtin >= 0)
		run_last_builtin(shell_state, builtin);
	else
	{
		if (spawn_pipeline_child(shell_state) < 0)
			return ;
		if (shell_state->pid == 0)
		{
			configure_signal_mode(SIGNAL_MODE_CHILD);
			wire_last_redirection(shell_state);
			run_external_command(shell_state);
		}
	}
	restore_stdio_fds(shell_state);
}
