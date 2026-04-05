#include "../../incl/minishell.h"

static int	count_heredoc_tokens(t_data *shell_state)
{
	t_token	*cursor;
	int		heredoc_count;

	cursor = shell_state->tokens;
	if (!cursor)
		return (0);
	heredoc_count = 0;
	while (cursor != NULL)
	{
		if (cursor->flag == TOKEN_HEREDOC)
			heredoc_count++;
		cursor = cursor->next;
	}
	return (heredoc_count);
}

void	analyze_tokens(t_data *shell_state)
{
	int	heredoc_count;

	shell_state->parse_error = false;
	reset_fd_state(shell_state);
	validate_pipe_sequence(shell_state);
	if (shell_state->parse_error == true)
		return ;
	collapse_joinable_tokens(shell_state);
	collapse_redirection_targets(shell_state);
	if (shell_state->parse_error == true)
		return ;
	heredoc_count = count_heredoc_tokens(shell_state);
	if (heredoc_count == 0)
		return ;
	shell_state->fd->hdoc = malloc(sizeof(char *) * (heredoc_count + 1));
	shell_state->fd->hdoc[heredoc_count] = NULL;
	parse_hdocs(shell_state);
}
