#include "../../incl/minishell.h"

void	free_cmd_and_path(t_data *shell_state)
{
	ft_cleansplit(shell_state->exec->cmd);
	shell_state->exec->cmd = NULL;
	free(shell_state->exec->path);
	shell_state->exec->path = NULL;
}

static void	resolve_command_target(t_data *shell_state, t_token *token_node)
{
	if (shell_state->exec->no_cmd == true || !shell_state->tokens->content)
		return ;
	if (token_node->content[0] == '.' || token_node->content[0] == CHAR_SLASH)
	{
		shell_state->exec->cmd = extract_cmd_from_path(shell_state);
		if (!shell_state->exec->cmd || !shell_state->exec->path)
		{
			shell_state->exec_error = true;
			return ;
		}
	}
	else
	{
		shell_state->exec->cmd = get_cmd(shell_state);
		if (shell_state->exec_error == true)
			return ;
		shell_state->exec->path = get_cmd_path(shell_state);
		if (!shell_state->exec->path)
			shell_state->exec_error = true;
	}
}

static void	dispatch_command(t_data *shell_state, t_token *token_node)
{
	resolve_command_target(shell_state, token_node);
	if (shell_state->exec->cmd_num < shell_state->exec->last_cmd)
		run_pipeline_stage(shell_state);
	else if (shell_state->exec->cmd_num == shell_state->exec->last_cmd)
		run_pipeline_last_stage(shell_state);
	free_cmd_and_path(shell_state);
}

static void	reset_command_state(t_data *shell_state)
{
	shell_state->parse_error = false;
	shell_state->exec_error = false;
	shell_state->exec->no_cmd = false;
	shell_state->fd->in = STDIN_FILENO;
	shell_state->fd->out = STDOUT_FILENO;
}

void	run_token_pipeline(t_data *shell_state)
{
	reset_exec_state(shell_state);
	shell_state->exec->last_cmd = count_pipeline_cmds(shell_state);
	shell_state->fd->hdoc_index = 0;
	while (shell_state->tokens != NULL)
	{
		reset_command_state(shell_state);
		apply_redirections(shell_state);
		if (!shell_state->tokens)
		{
			restore_stdio_fds(shell_state);
			sync_pipeline_exit_code(shell_state);
		}
		else if (shell_state->exec->no_cmd == true || shell_state->tokens->flag == TOKEN_WORD)
		{
			dispatch_command(shell_state, shell_state->tokens);
			shell_state->exec->cmd_num++;
		}
		delete_words(shell_state);
		ft_del_first_token(&shell_state);
		close_fds_in_out(shell_state);
	}
	update_child_exit_code(shell_state);
	clear_heredoc_files(shell_state);
}
