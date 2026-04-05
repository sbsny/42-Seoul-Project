#include "../../incl/minishell.h"

int	run_cd_dash(t_data *shell_state)
{
	int	status_code;

	status_code = resolve_home_path(shell_state->exec->cmd, shell_state);
	if (status_code == EXIT_FAILURE)
		return (EXIT_FAILURE);
	status_code = update_working_dirs(shell_state);
	builtin_pwd();
	return (status_code);
}

int	run_cd_tilde(t_data *shell_state)
{
	int	status_code;

	status_code = resolve_home_path(shell_state->exec->cmd, shell_state);
	if (status_code == 0)
		status_code = update_working_dirs(shell_state);
	return (status_code);
}

int	run_cd_path(t_data *shell_state)
{
	int	status_code;

	status_code = chdir(shell_state->exec->cmd[1]);
	if (status_code == 0)
		status_code = update_working_dirs(shell_state);
	return (status_code);
}

int	run_cd_home(t_data *shell_state)
{
	int		status_code;
	t_builtin_envp	*cursor_node;

	cursor_node = ft_getbuiltin_envp(shell_state, "HOME");
	if (!cursor_node || ft_strlen(cursor_node->val) == 0)
	{
		exec_error(ERR_EMPTY_KEY, "HOME");
		return (EXIT_FAILURE);
	}
	status_code = chdir(cursor_node->val);
	update_working_dirs(shell_state);
	return (status_code);
}

int	builtin_cd(t_data *shell_state)
{
	int		status_code;

	if (shell_state->exec->last_cmd > 1)
		return (EXIT_FAILURE);
	if (!shell_state->exec->cmd[1])
		return (run_cd_home(shell_state));
	else if (shell_state->exec->cmd[1][0] == '-')
		return (run_cd_dash(shell_state));
	else if (shell_state->exec->cmd[1][0] == '~')
		status_code = run_cd_tilde(shell_state);
	else
		status_code = run_cd_path(shell_state);
	if (status_code != 0)
	{
		exec_error(ERR_PATH, shell_state->exec->cmd[1]);
		return (EXIT_FAILURE);
	}
	return (status_code);
}
