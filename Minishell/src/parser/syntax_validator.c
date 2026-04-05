#include "../../incl/minishell.h"

void	validate_input_fd(t_data *shell_state, t_token *operator_token)
{
	char	*redir_target_path;

	redir_target_path = operator_token->content;
	if (!redir_target_path || shell_state->fd->in < 0)
	{
		if (access(redir_target_path, F_OK < 0))
			exec_error(ERR_PATH, redir_target_path);
		else if (access(redir_target_path, R_OK) < 0)
			exec_error(ERR_PERMISSION, redir_target_path);
		shell_state->parse_error = true;
	}
}

void	validate_output_fd(t_data *shell_state, t_token *operator_token)
{
	char	*redir_target_path;

	redir_target_path = operator_token->content;
	if (!redir_target_path || shell_state->fd->out < 0)
	{
		if (access(redir_target_path, F_OK) < 0)
			exec_error(ERR_PATH, redir_target_path);
		else if (access(redir_target_path, W_OK) < 0)
			exec_error(ERR_PERMISSION, redir_target_path);
		shell_state->parse_error = true;
	}
}

void	validate_pipe_sequence(t_data *shell_state)
{
	t_token	*token_cursor;

	token_cursor = shell_state->tokens;
	if (!token_cursor)
		return ;
	while (token_cursor->next != NULL)
	{
		if (token_cursor->flag == TOKEN_PIPE)
		{
			if (token_cursor->next->flag == TOKEN_PIPE)
			{
				print_token_error(ERR_PIPE_SYNTAX, token_cursor);
				shell_state->parse_error = true;
				g_exit_code = ERR_PIPE_SYNTAX;
				return ;
			}
		}
		token_cursor = token_cursor->next;
	}
	if (token_cursor->flag == TOKEN_PIPE)
	{
		print_token_error(ERR_PIPE_SYNTAX, token_cursor);
		g_exit_code = ERR_PIPE_SYNTAX;
		shell_state->parse_error = true;
	}
}

bool	has_redirection_syntax_error(t_data *shell_state,
	t_token *operator_token)
{
	if (operator_token->next == NULL || operator_token->next->flag != TOKEN_WORD)
	{
		print_token_error(ERR_REDIR_SYNTAX, operator_token);
		g_exit_code = ERR_PIPE_SYNTAX;
		shell_state->parse_error = true;
		return (true);
	}
	return (false);
}

bool	is_redirection_token(t_data *shell_state, int redirection_flag)
{
	int	redir_index;

	redir_index = 0;
	while (redir_index < REDIRECTION_COUNT)
	{
		if (redirection_flag == shell_state->redir[redir_index])
			return (true);
		redir_index++;
	}
	return (false);
}
