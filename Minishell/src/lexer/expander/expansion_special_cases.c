#include "../../../incl/minishell.h"

void	expand_last_return(t_data *shell_state, t_lex *lex)
{
	char	*exit_code;
	bool	is_sep;

	exit_code = ft_itoa(g_exit_code);
	lex->buf = ft_strjoin(lex->buf, exit_code);
	free(exit_code);
	exit_code = NULL;
	lex->i++;
	lex->c = shell_state->input[lex->i];
	is_sep = check_sep(shell_state, lex->c);
	while (is_sep == false && lex->c != '\0')
	{
		is_sep = check_sep(shell_state, lex->c);
		if (is_sep == true)
			break ;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = shell_state->input[lex->i];
	}
}

void	handle_multiple_dollars(t_data *shell_state, t_lex *lex)
{
	bool	is_sep;

	while (lex->c == CHAR_DOLLAR)
	{
		lex->buf = ft_join_char(lex->buf, CHAR_DOLLAR);
		lex->i++;
		lex->c = shell_state->input[lex->i];
	}
	is_sep = check_sep(shell_state, lex->c);
	if (is_sep == true && lex->c != CHAR_DOUBLE_QUOTE && lex->c != CHAR_SINGLE_QUOTE)
	{
		lex->expansion = false;
		if (lex->double_quote_mode == false)
			append_token(shell_state, lex);
	}
	else
	{
		if (lex->double_quote_mode == false)
			append_token(shell_state, lex);
		lex->expansion = false;
	}
}

void	handle_one_dollar(t_data *shell_state, t_lex *lex)
{
	bool	is_sep;

	lex->buf = ft_join_char(lex->buf, CHAR_DOLLAR);
	is_sep = check_sep(shell_state, lex->c);
	if (is_sep == true && lex->c != CHAR_DOUBLE_QUOTE && lex->c != CHAR_SINGLE_QUOTE)
	{
		lex->expansion = false;
		if (lex->double_quote_mode == false)
			append_token(shell_state, lex);
	}
	else
	{
		if (lex->double_quote_mode == false)
			append_token(shell_state, lex);
		lex->expansion = false;
	}
	lex->i++;
}
