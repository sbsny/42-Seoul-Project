#include "../../../incl/minishell.h"

void	close_fds_in_out(t_data *shell_state)
{
	if (shell_state->fd->in != STDIN_FILENO)
		close(shell_state->fd->in);
	if (shell_state->fd->out != STDOUT_FILENO)
		close(shell_state->fd->out);
}

void	close_unused_fd_out(t_data *shell_state)
{
	if (shell_state->fd->out == STDOUT_FILENO)
		return ;
	else if (close(shell_state->fd->out) < 0)
		perror(NULL);
}

void	close_unused_fd_in(t_data *shell_state)
{
	if (shell_state->fd->in == STDIN_FILENO)
		return ;
	else if (close(shell_state->fd->in) < 0)
		perror(NULL);
}
