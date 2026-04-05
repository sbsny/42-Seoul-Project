#include "../../../incl/minishell.h"

void	redirect_from_hdoc(t_data *shell_state)
{
	char	*heredoc_path;

	heredoc_path = shell_state->fd->hdoc[shell_state->fd->hdoc_index];
	close_unused_fd_in(shell_state);
	if (shell_state->parse_error == true)
		return ;
	shell_state->fd->in = open(heredoc_path, O_RDONLY);
	if (access(heredoc_path, F_OK) < 0)
	{
		exec_error(ERR_PATH, heredoc_path);
		shell_state->parse_error = true;
	}
	else if (access(heredoc_path, R_OK) < 0)
	{
		exec_error(ERR_PERMISSION, heredoc_path);
		shell_state->parse_error = true;
	}
}

void	redirect_in(t_data *shell_state, t_token *redirect_target_token)
{
	close_unused_fd_in(shell_state);
	if (shell_state->parse_error == true)
		return ;
	shell_state->fd->in = open(redirect_target_token->content, O_RDONLY);
	validate_input_fd(shell_state, redirect_target_token);
}

void	redirect_out(t_data *shell_state, t_token *redirect_target_token)
{
	close_unused_fd_out(shell_state);
	shell_state->fd->out = open(redirect_target_token->content,
			O_CREAT | O_RDWR | O_TRUNC, FILE_DEFAULT_RIGHTS);
	validate_output_fd(shell_state, redirect_target_token);
}

void	append(t_data *shell_state, t_token *redirect_target_token)
{
	close_unused_fd_out(shell_state);
	shell_state->fd->out = open(redirect_target_token->content,
			O_CREAT | O_RDWR | O_APPEND, FILE_DEFAULT_RIGHTS);
	validate_output_fd(shell_state, redirect_target_token);
}
