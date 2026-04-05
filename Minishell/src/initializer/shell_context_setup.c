#include "../../incl/minishell.h"

static void	setup_builtin_registry(t_data *shell_state)
{
	load_builtin_names(shell_state);
	load_builtin_handlers(shell_state);
}

static void	setup_separator_table(t_data *shell_state)
{
	shell_state->sep = malloc(sizeof(char) * 8);
	if (!shell_state->sep)
	{
		free(shell_state->redir);
		shell_state->redir = NULL;
		exit(EXIT_FAILURE);
	}
	shell_state->sep[0] = CHAR_SPACE;
	shell_state->sep[1] = CHAR_SINGLE_QUOTE;
	shell_state->sep[2] = CHAR_DOUBLE_QUOTE;
	shell_state->sep[3] = CHAR_REDIRECT_IN;
	shell_state->sep[4] = CHAR_REDIRECT_OUT;
	shell_state->sep[5] = CHAR_PIPE;
	shell_state->sep[6] = CHAR_DOLLAR;
	shell_state->sep[7] = '\0';
}

static void	setup_redirection_table(t_data *shell_state)
{
	shell_state->redir = malloc(sizeof(int) * 4);
	if (!shell_state->redir)
		exit(EXIT_FAILURE);
	shell_state->redir[0] = TOKEN_REDIRECT_IN;
	shell_state->redir[1] = TOKEN_REDIRECT_OUT;
	shell_state->redir[2] = TOKEN_HEREDOC;
	shell_state->redir[3] = TOKEN_APPEND;
}

void	allocate_shell_context(t_data *shell_state)
{
	shell_state->input = NULL;
	shell_state->redir = NULL;
	shell_state->sep = NULL;
	shell_state->builtin_envp = NULL;
	shell_state->tokens = NULL;
	setup_redirection_table(shell_state);
	setup_separator_table(shell_state);
	setup_builtin_registry(shell_state);
}
