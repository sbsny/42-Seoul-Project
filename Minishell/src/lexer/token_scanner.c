#include "../../incl/minishell.h"

bool	check_sep(t_data *shell_state, char c)
{
	int	sep_index;

	sep_index = 0;
	while (shell_state->sep[sep_index] != '\0')
	{
		if (c == shell_state->sep[sep_index])
			return (true);
		sep_index++;
	}
	return (false);
}

static void	set_exp_join_flag(t_data *shell_state, t_lex *lex, t_token *token_node)
{
	char	next_char;

	next_char = shell_state->input[lex->i + 1];
	if (lex->c == CHAR_SINGLE_QUOTE || lex->c == CHAR_DOUBLE_QUOTE || lex->c == CHAR_DOLLAR
		|| lex->c == CHAR_SLASH)
	{
		if (lex->double_quote_mode == true)
		{
			if (next_char == CHAR_SPACE || next_char == CHAR_REDIRECT_OUT
				|| next_char == CHAR_REDIRECT_IN || next_char == CHAR_PIPE
				|| next_char == '\0')
				return ;
			else
				token_node->join = true;
		}
		else
			token_node->join = true;
	}
}

static void	set_join_flag(t_data *shell_state, t_lex *lex, t_token *token_node)
{
	token_node->join = false;
	if (lex->expansion == true)
		set_exp_join_flag(shell_state, lex, token_node);
	else
	{
		if (shell_state->input[lex->i] == CHAR_SLASH)
			token_node->join = true;
	}
}

void	append_token(t_data *shell_state, t_lex *lex)
{
	t_token	*new_token;
	char	*content;

	if (!lex->buf)
		return ;
	new_token = NULL;
	content = ft_strdup(lex->buf);
	if (!content)
		return ;
	new_token = ft_new_token(content, lex->flag);
	set_join_flag(shell_state, lex, new_token);
	ft_append_token_back(&shell_state->tokens, new_token);
	free(lex->buf);
	lex->buf = NULL;
}

void	scan_input_tokens(t_data *shell_state, t_lex *lex)
{
	bool	redirect_found;

	while (shell_state->input[lex->i] != '\0' && shell_state->lex_error == false)
	{
		lex->c = shell_state->input[lex->i];
		redirect_found = find_redirections(lex);
		if (redirect_found)
			handle_redirections(shell_state, lex);
		else if (lex->c == CHAR_SPACE)
			lex->i++;
		else if (lex->c == CHAR_SINGLE_QUOTE)
			handle_single_quotes(shell_state, lex);
		else if (lex->c == CHAR_DOLLAR)
			handle_expansion(shell_state, lex);
		else if (lex->c == CHAR_DOUBLE_QUOTE)
			handle_double_quotes(shell_state, lex);
		else
			handle_words(shell_state, lex);
	}
}
