#include "../../incl/minishell.h"

int	check_exit_args(t_data *shell_state, bool *arg_equal_one)
{
	int	i;

	i = 0;
	while (shell_state->exec->cmd[i])
		i++;
	if (i > 1)
	{
		if (ft_isnumber(shell_state->exec->cmd[1], 0, 0) && i == 2)
			return (ft_atoi(shell_state->exec->cmd[1]) % 256);
		else if (ft_isnumber(shell_state->exec->cmd[1], 0, 0) && i > 2)
		{
			*arg_equal_one = false;
			print_error(ERR_EXIT);
			return (EXIT_FAILURE);
		}
		else if (!ft_isnumber(shell_state->exec->cmd[1], 0, 0))
		{
			exec_error(ERR_EXIT_ARG, shell_state->exec->cmd[1]);
			return (EXIT_INVALID_ARG);
		}
	}
	return (EXIT_SUCCESS);
}

int	builtin_exit(t_data *shell_state)
{
	int		status_code;
	bool	arg_equal_one;

	arg_equal_one = true;
	status_code = check_exit_args(shell_state, &arg_equal_one);
	if (arg_equal_one == true)
	{
		write(2, "exit\n", 5);
		shell_state->exit_minishell = true;
	}
	return (status_code);
}
