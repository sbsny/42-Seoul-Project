#include "../../incl/minishell.h"

static bool	validate_builtin_name_alloc(t_data *shell_state)
{
	int	i;

	i = 0;
	while (i < BUILTIN_COUNT)
	{
		if (shell_state->builtins->names[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

void	load_builtin_names(t_data *shell_state)
{
	bool	all_names_malloced;

	shell_state->builtins = malloc(sizeof(t_builtins));
	if (!shell_state->builtins)
		exit(EXIT_FAILURE);
	shell_state->builtins->names[0] = ft_strdup("builtin_echo");
	shell_state->builtins->names[1] = ft_strdup("builtin_cd");
	shell_state->builtins->names[2] = ft_strdup("builtin_pwd");
	shell_state->builtins->names[3] = ft_strdup("builtin_export");
	shell_state->builtins->names[4] = ft_strdup("builtin_unset");
	shell_state->builtins->names[5] = ft_strdup("builtin_env");
	shell_state->builtins->names[6] = ft_strdup("exit");
	all_names_malloced = validate_builtin_name_alloc(shell_state);
	if (all_names_malloced == false)
	{
		clear_builtin_table(shell_state);
		exit(EXIT_FAILURE);
	}
}

void	load_builtin_handlers(t_data *shell_state)
{
	shell_state->builtins->funcs[0] = (void *)&builtin_echo;
	shell_state->builtins->funcs[1] = (void *)&builtin_cd;
	shell_state->builtins->funcs[2] = (void *)&builtin_pwd;
	shell_state->builtins->funcs[3] = (void *)&builtin_export;
	shell_state->builtins->funcs[4] = (void *)&builtin_unset;
	shell_state->builtins->funcs[5] = (void *)&builtin_env;
	shell_state->builtins->funcs[6] = (void *)&builtin_exit;
}
