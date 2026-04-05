#include "../../incl/minishell.h"

bool	is_quote_unclosed(t_data *shell_state, t_lex *lex)
{
	int	scan_index;

	scan_index = lex->i + 1;
	if (lex->c == CHAR_SINGLE_QUOTE)
	{
		while (shell_state->input[scan_index] != '\0')
		{
			if (shell_state->input[scan_index] == CHAR_SINGLE_QUOTE)
				return (false);
			scan_index++;
		}
	}
	else if (lex->c == CHAR_DOUBLE_QUOTE)
	{
		while (shell_state->input[scan_index] != '\0')
		{
			if (shell_state->input[scan_index] == CHAR_DOUBLE_QUOTE)
				return (false);
			scan_index++;
		}
	}
	return (true);
}

void	abort_lexing(t_data *shell_state, t_lex *lex)
{
	shell_state->lex_error = true;
	free(lex->buf);
	lex->buf = NULL;
	if (lex->c == CHAR_SINGLE_QUOTE)
		print_error(ERR_SINGLE_QUOTE_MISSING);
	else if (lex->c == CHAR_DOUBLE_QUOTE)
		print_error(ERR_DOUBLE_QUOTE_MISSING);
}

static void	handle_empty_single_quotes(t_data *shell_state, t_lex *lex)
{
	t_token	*new_token;
	char	*content;
	bool	redirect_found;

	lex->buf = ft_join_char(lex->buf, '\0');
	lex->i++;
	lex->c = shell_state->input[lex->i];
	content = ft_strdup(lex->buf);
	if (!content)
		return ;
	new_token = ft_new_token(content, lex->flag);
	redirect_found = find_redirections(lex);
	if (lex->c != CHAR_SPACE && redirect_found == false && lex->c != '\0')
		new_token->join = true;
	ft_append_token_back(&shell_state->tokens, new_token);
	free(lex->buf);
	lex->buf = NULL;
}

static void	handle_quotes_content(t_data *shell_state, t_lex *lex)
{
	bool	redirect_found;

	while (lex->c != CHAR_SINGLE_QUOTE)
	{
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = shell_state->input[lex->i];
	}
	lex->i++;
	lex->c = shell_state->input[lex->i];
	redirect_found = find_redirections(lex);
	if (lex->c == CHAR_SPACE || redirect_found == true || lex->c == '\0')
		append_token(shell_state, lex);
}

void	handle_single_quotes(t_data *shell_state, t_lex *lex)
{
	bool	quote_not_closed;

	lex->single_quote_mode = true;
	quote_not_closed = is_quote_unclosed(shell_state, lex);
	if (quote_not_closed)
	{
		abort_lexing(shell_state, lex);
		return ;
	}
	lex->flag = TOKEN_WORD;
	lex->i++;
	lex->c = shell_state->input[lex->i];
	if (shell_state->input[lex->i] == CHAR_SINGLE_QUOTE)
		handle_empty_single_quotes(shell_state, lex);
	else
		handle_quotes_content(shell_state, lex);
	lex->single_quote_mode = false;
}
