#include "../incl/minishell.h"

void	capture_prompt_history(t_data *shell_state)
{
	shell_state->input = readline("minishell$ ");
	if (!shell_state->input)
	{
		printf("exit\n");
		shutdown_shell(shell_state);
		exit(g_exit_code);
	}
	if (ft_strlen(shell_state->input) != 0)
		add_history(shell_state->input);
}
