#include "../../incl/minishell.h"

void	reset_fd_state(t_data *shell_state)
{
	shell_state->fd->hdoc = NULL;
	shell_state->fd->in = STDIN_FILENO;
	shell_state->fd->out = STDOUT_FILENO;
	shell_state->fd->hdoc_index = 0;
}

void	backup_stdio_fds(t_data *shell_state)
{
	shell_state->fd->std_in = dup(STDIN_FILENO);
	if (!shell_state->fd->std_in)
	{
		free(shell_state->fd);
		exit(EXIT_FAILURE);
	}
	shell_state->fd->std_out = dup(STDOUT_FILENO);
	if (!shell_state->fd->std_out)
	{
		free(shell_state->fd);
		exit(EXIT_FAILURE);
	}
}
