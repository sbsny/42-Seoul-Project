#include "../../incl/minishell.h"

static int	set_builtin_pwd(t_data *shell_state, char **builtin_pwd_path, t_builtin_envp **builtin_pwd)
{
	if ((*builtin_pwd != NULL))
	{
		if ((*builtin_pwd)->val != NULL)
			free((*builtin_pwd)->val);
		(*builtin_pwd)->val = ft_strdup(*builtin_pwd_path);
		if (!(*builtin_pwd)->val)
			return (EXIT_FAILURE);
	}
	else
	{
		*builtin_pwd = ft_new_builtin_envp(ft_strdup("PWD"), ft_strdup(*builtin_pwd_path));
		if (!(*builtin_pwd))
			return (EXIT_FAILURE);
		ft_add_builtin_envp_back(&shell_state->builtin_envp, *builtin_pwd);
	}
	return (EXIT_SUCCESS);
}

static int	set_oldbuiltin_pwd(t_data *shell_state, t_builtin_envp **builtin_pwd, t_builtin_envp **old)
{
	if ((*old != NULL))
	{
		if ((*old)->val != NULL)
			free((*old)->val);
		(*old)->val = ft_strdup((*builtin_pwd)->val);
		if (!(*old)->val)
			return (EXIT_FAILURE);
	}
	else
	{
		*old = ft_new_builtin_envp(ft_strdup("OLDPWD"), ft_strdup((*builtin_pwd)->val));
		if (!(*old) || ft_strlen((*builtin_pwd)->val) == 0)
			return (EXIT_FAILURE);
		ft_add_builtin_envp_back(&shell_state->builtin_envp, *old);
	}
	return (EXIT_SUCCESS);
}

int	fill_empty_builtin_pwd(t_data *shell_state, char **builtin_pwd_path, t_builtin_envp **builtin_pwd, t_builtin_envp **old)
{
	int	status_code;

	status_code = EXIT_SUCCESS;
	if (!(*builtin_pwd) || ft_strlen((*builtin_pwd)->val) == 0)
		status_code = set_builtin_pwd(shell_state, builtin_pwd_path, builtin_pwd);
	if (!(*old) || ft_strlen((*old)->val) == 0)
		status_code = set_oldbuiltin_pwd(shell_state, builtin_pwd, old);
	return (status_code);
}
