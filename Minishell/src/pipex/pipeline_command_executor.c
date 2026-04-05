#include "../../incl/minishell.h"

void	run_external_command(t_data *shell_state)
{
	if (g_exit_code == EXIT_SIGINT)
		exit(EXIT_SIGINT);
	if (shell_state->exec_error == true)
	{
		restore_stdio_fds(shell_state);
		exec_error(EXIT_CMD_NOT_FOUND, shell_state->exec->cmd[0]);
		exit(EXIT_CMD_NOT_FOUND);
	}
	else
	{
		if (execve(shell_state->exec->path, shell_state->exec->cmd, shell_state->builtin_env) < 0)
		{
			restore_stdio_fds(shell_state);
			exec_error(EXIT_CMD_NOT_FOUND, shell_state->exec->cmd[0]);
			exit(EXIT_CMD_NOT_FOUND);
		}
	}
	exit(EXIT_SUCCESS);
}

void	run_stage_builtin(t_data *shell_state, int builtin)
{
	if (shell_state->fd->in != STDIN_FILENO)
	{
		if (dup2(shell_state->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->in);
	}
	if (shell_state->fd->out != STDOUT_FILENO)
	{
		if (dup2(shell_state->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->out);
	}
	else
		dup2(shell_state->pipe[1], STDOUT_FILENO);
	g_exit_code = shell_state->builtins->funcs[builtin](shell_state);
	dup2(shell_state->pipe[0], STDIN_FILENO);
	close(shell_state->pipe[1]);
	close(shell_state->pipe[0]);
	dup2(shell_state->fd->std_out, STDOUT_FILENO);
}

void	run_last_builtin(t_data *shell_state, int builtin)
{
	if (shell_state->fd->in != STDIN_FILENO)
	{
		if (dup2(shell_state->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->in);
	}
	if (shell_state->fd->out != STDOUT_FILENO)
	{
		if (dup2(shell_state->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->out);
	}
	g_exit_code = shell_state->builtins->funcs[builtin](shell_state);
}

void	wire_stage_redirection(t_data *shell_state)
{
	close(shell_state->pipe[0]);
	if (shell_state->fd->in != STDIN_FILENO)
	{
		if (dup2(shell_state->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->in);
	}
	if (shell_state->fd->out != STDOUT_FILENO)
	{
		if (dup2(shell_state->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->out);
	}
	else
		dup2(shell_state->pipe[1], STDOUT_FILENO);
	close(shell_state->pipe[1]);
}

void	wire_last_redirection(t_data *shell_state)
{
	if (shell_state->fd->in != STDIN_FILENO)
	{
		if (dup2(shell_state->fd->in, STDIN_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->in);
	}
	if (shell_state->fd->out != STDOUT_FILENO)
	{
		if (dup2(shell_state->fd->out, STDOUT_FILENO) < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		close(shell_state->fd->out);
	}
}
