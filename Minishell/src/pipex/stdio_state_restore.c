#include "../../incl/minishell.h"

void	restore_stdio_fds(t_data *shell_state)
{
	dup2(shell_state->fd->std_in, STDIN_FILENO);
	dup2(shell_state->fd->std_out, STDOUT_FILENO);
}

void	sync_pipeline_exit_code(t_data *shell_state)
{
	if (shell_state->parse_error == true)
		g_exit_code = EXIT_FAILURE;
	else if (g_exit_code != EXIT_SIGINT)
		g_exit_code = EXIT_SUCCESS;
}
