#include "../../incl/minishell.h"

void	handle_words(t_data *shell_state, t_lex *lex)
{
	bool	redirect_found;

	lex->buf = ft_join_char(lex->buf, lex->c);
	lex->flag = TOKEN_WORD;
	lex->i++;
	lex->c = shell_state->input[lex->i];
	redirect_found = find_redirections(lex);
	if (lex->c == CHAR_SPACE || redirect_found == true || lex->c == '\0')
		append_token(shell_state, lex);
}
