#include "../../incl/minishell.h"

void	init_lex(t_lex *lex)
{
	lex->i = 0;
	lex->c = 0;
	lex->buf = NULL;
	lex->flag = 0;
	lex->expansion = false;
	lex->single_quote_mode = false;
	lex->double_quote_mode = false;
}

void	tokenize_input(t_data *shell_state)
{
	t_lex	lex;

	init_lex(&lex);
	shell_state->lex_error = false;
	shell_state->input = ft_strtrim(shell_state->input, CHAR_SPACE);
	scan_input_tokens(shell_state, &lex);
	free(shell_state->input);
	shell_state->input = NULL;
	if (shell_state->lex_error == true)
		g_exit_code = EXIT_FAILURE;
}
