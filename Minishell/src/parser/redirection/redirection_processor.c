#include "../../../incl/minishell.h"

void	forward_pipe_input(t_data *shell_state)
{
	close(shell_state->pipe[1]);
	dup2(shell_state->pipe[0], STDIN_FILENO);
	close(shell_state->pipe[0]);
}

static void	apply_redirection_token(t_data *shell_state, t_token *token_node)
{
	if (token_node->flag == TOKEN_REDIRECT_IN)
		redirect_in(shell_state, token_node);
	else if (token_node->flag == TOKEN_HEREDOC)
	{
		redirect_from_hdoc(shell_state);
		shell_state->fd->hdoc_index++;
	}
	else if (token_node->flag == TOKEN_REDIRECT_OUT)
		redirect_out(shell_state, token_node);
	else if (token_node->flag == TOKEN_APPEND)
		append(shell_state, token_node);
	if (shell_state->parse_error == true)
		g_exit_code = EXIT_FAILURE;
}

static void	consume_redirection_token(t_data *shell_state, t_token *token_node)
{
	if (shell_state->parse_error == false)
		apply_redirection_token(shell_state, token_node);
	free(token_node->content);
	token_node->content = NULL;
	free(token_node);
	token_node = NULL;
}

static void	strip_inline_redirections(t_data *shell_state)
{
	t_token	*prev;
	t_token	*cursor;

	prev = shell_state->tokens;
	cursor = shell_state->tokens->next;
	while (cursor != NULL && cursor->flag != TOKEN_PIPE)
	{
		if (is_redirection_token(shell_state, cursor->flag) == true)
		{
			prev->next = cursor->next;
			consume_redirection_token(shell_state, cursor);
			cursor = prev->next;
		}
		else
		{
			prev = prev->next;
			cursor = cursor->next;
		}
	}
}

void	apply_redirections(t_data *shell_state)
{
	t_token	*cursor;

	cursor = shell_state->tokens;
	if (!cursor || cursor->flag == TOKEN_PIPE)
		return ;
	while (cursor && is_redirection_token(shell_state, cursor->flag) == true)
	{
		shell_state->tokens = cursor->next;
		consume_redirection_token(shell_state, cursor);
		cursor = shell_state->tokens;
	}
	if (cursor == NULL || cursor->flag == TOKEN_PIPE)
	{
		shell_state->exec->no_cmd = true;
		return ;
	}
	strip_inline_redirections(shell_state);
}
