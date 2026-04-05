#include "../../incl/minishell.h"

int	update_working_dirs(t_data *shell_state)
{
	t_builtin_envp	*old;
	t_builtin_envp	*builtin_pwd;
	char	*builtin_pwd_path;
	char	*new_builtin_pwd;
	char	*new_old;

	builtin_pwd_path = NULL;
	builtin_pwd_path = getcwd(builtin_pwd_path, 0);
	builtin_pwd = ft_getbuiltin_envp(shell_state, "PWD");
	old = ft_getbuiltin_envp(shell_state, "OLDPWD");
	if (fill_empty_builtin_pwd(shell_state, &builtin_pwd_path, &builtin_pwd, &old) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	new_old = ft_strdup(builtin_pwd->val);
	if (!new_old)
		return (EXIT_FAILURE);
	new_builtin_pwd = ft_strdup(builtin_pwd_path);
	if (!new_builtin_pwd)
		return (EXIT_FAILURE);
	free(builtin_pwd->val);
	builtin_pwd->val = new_builtin_pwd;
	free(old->val);
	old->val = new_old;
	free(builtin_pwd_path);
	return (EXIT_SUCCESS);
}

static int	builtin_pwd_switch(t_data *shell_state, const char *option_arg)
{
	t_builtin_envp	*cursor_node;

	if (option_arg[1] != '\0')
		return (-1);
	cursor_node = ft_getbuiltin_envp(shell_state, "OLDPWD");
	if (!cursor_node || ft_strlen(cursor_node->val) == 0)
	{
		exec_error(ERR_EMPTY_KEY, "OLDPWD");
		return (EXIT_FAILURE);
	}
	else
		chdir(cursor_node->val);
	return (EXIT_SUCCESS);
}

static int	join_tilde_with_path(t_data *shell_state, char **arguments)
{
	int		res;
	char	*path;
	char	*status_code;
	int		j;

	j = 1;
	path = malloc(sizeof(char) * (ft_strlen(arguments[1])));
	if (!path)
		return (EXIT_FAILURE);
	while (arguments[1][j])
	{
		path[j - 1] = arguments[1][j];
		j++;
	}
	path[j - 1] = '\0';
	status_code = ft_join_tilde(shell_state->builtins->home, path, j);
	if (!status_code)
		return (EXIT_FAILURE);
	res = chdir(status_code);
	free(status_code);
	return (res);
}

int	resolve_home_path(char **arguments, t_data *shell_state)
{
	int	status_code;

	status_code = EXIT_SUCCESS;
	if (arguments[1][0] == '-')
		status_code = builtin_pwd_switch(shell_state, arguments[1]);
	if (arguments[1][0] == '~')
		status_code = join_tilde_with_path(shell_state, arguments);
	return (status_code);
}
