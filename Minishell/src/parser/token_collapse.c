#include "../../incl/minishell.h"

static bool	can_merge_word_token(t_token *current)
{
	if (current == NULL || current->next == NULL)
		return (false);
	return (current->join == true && current->next->flag == TOKEN_WORD);
}

void	normalize_join_flags(t_data *shell_state)
{
	t_token	*cursor;

	cursor = shell_state->tokens;
	while (cursor->next != NULL)
	{
		if (cursor->join == true && cursor->next->flag != TOKEN_WORD)
			cursor->join = false;
		cursor = cursor->next;
	}
}

void	collapse_joinable_tokens(t_data *shell_state)
{
	t_token	*cursor;
	t_token	*next_token;

	cursor = shell_state->tokens;
	if (!cursor)
		return ;
	normalize_join_flags(shell_state);
	next_token = NULL;
	while (cursor->next != NULL)
	{
		if (can_merge_word_token(cursor) == true)
		{
			next_token = cursor->next;
			cursor->content = ft_strjoin(cursor->content, next_token->content);
			cursor->join = next_token->join;
			cursor->next = next_token->next;
			free(next_token->content);
			next_token->content = NULL;
			free(next_token);
			next_token = NULL;
		}
		else
			cursor = cursor->next;
	}
	cursor->join = false;
}

void	collapse_redirection_targets(t_data *shell_state)
{
	t_token	*cursor;
	t_token	*next_token;
	bool	is_redir;

	cursor = shell_state->tokens;
	if (!cursor)
		return ;
	while (cursor != NULL)
	{
		is_redir = is_redirection_token(shell_state, cursor->flag);
		if (is_redir == true)
		{
			next_token = cursor->next;
			if (has_redirection_syntax_error(shell_state, cursor) == true)
				return ;
			free(cursor->content);
			cursor->content = NULL;
			cursor->content = next_token->content;
			cursor->next = next_token->next;
			free(next_token);
			next_token = NULL;
		}
		cursor = cursor->next;
	}
}

void	delete_words(t_data *shell_state)
{
	t_token	*next_node;

	next_node = shell_state->tokens;
	if (!next_node)
		return ;
	while (next_node != NULL && next_node->flag != TOKEN_PIPE)
	{
		next_node = next_node->next;
		free(shell_state->tokens->content);
		shell_state->tokens->content = NULL;
		free(shell_state->tokens);
		shell_state->tokens = NULL;
		shell_state->tokens = next_node;
	}
}
