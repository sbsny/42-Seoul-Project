#include "../../incl/minishell.h"

static void	lex_pipe(t_lex *lex)
{
	if (lex->c == '|')
	{
		lex->flag = TOKEN_PIPE;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
	}
}

static void	lex_redirect_out(t_data *shell_state, t_lex *lex)
{
	if (lex->c == '>')
	{
		lex->flag = TOKEN_REDIRECT_OUT;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = shell_state->input[lex->i];
		if (lex->c == '>')
		{
			lex->flag = TOKEN_APPEND;
			lex->buf = ft_join_char(lex->buf, lex->c);
			lex->i++;
		}
	}
}

static void	lex_redirect_in(t_data *shell_state, t_lex *lex)
{
	if (lex->c == '<')
	{
		lex->flag = TOKEN_REDIRECT_IN;
		lex->buf = ft_join_char(lex->buf, lex->c);
		lex->i++;
		lex->c = shell_state->input[lex->i];
		if (lex->c == '<')
		{
			lex->flag = TOKEN_HEREDOC;
			lex->buf = ft_join_char(lex->buf, lex->c);
			lex->i++;
		}
	}
}

void	handle_redirections(t_data *shell_state, t_lex *lex)
{
	if (lex->c == '<')
		lex_redirect_in(shell_state, lex);
	else if (lex->c == '>')
		lex_redirect_out(shell_state, lex);
	else
		lex_pipe(lex);
	append_token(shell_state, lex);
}

bool	find_redirections(t_lex *lex)
{
	if (lex->c == '<' || lex->c == '>' || lex->c == '|')
		return (true);
	return (false);
}
