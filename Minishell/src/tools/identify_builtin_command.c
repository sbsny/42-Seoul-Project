#include "../../incl/minishell.h"

int	identify_builtin_cmd(t_data *shell_state)
{
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[0]) == 0)
		return (0);
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[1]) == 0)
		return (1);
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[2]) == 0)
		return (2);
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[3]) == 0)
		return (3);
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[4]) == 0)
		return (4);
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[5]) == 0)
		return (5);
	if (ft_strcmp(shell_state->exec->cmd[0], shell_state->builtins->names[6]) == 0)
		return (6);
	return (-1);
}
