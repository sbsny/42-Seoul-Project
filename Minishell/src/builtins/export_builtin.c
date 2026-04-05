#include "../../incl/minishell.h"

static char	*build_export_value(char *argument, int assign_index, int append_mode)
{
	char	*env_value;

	env_value = NULL;
	if (argument[assign_index] != '\0' && argument[assign_index + 1] != '\0'
		&& !append_mode)
		env_value = ft_strdup(argument + assign_index + 1);
	else if (argument[assign_index] != '\0' && argument[assign_index + 1] != '\0'
		&& append_mode)
	{
		assign_index++;
		if (argument[assign_index] != '\0' && argument[assign_index + 1] != '\0')
			env_value = ft_strdup(argument + assign_index + 1);
	}
	if (env_value == NULL)
		env_value = ft_strdup("");
	return (env_value);
}

static void	merge_existing_export_key(t_builtin_envp *existing_entry,
		char *env_value, char *env_key, int append_mode)
{
	if (existing_entry->equal == 0)
	{
		free(env_key);
		free(env_value);
		return ;
	}
	free(env_key);
	if (append_mode)
	{
		existing_entry->val = ft_strjoin(existing_entry->val, env_value);
		free(env_value);
		return ;
	}
	free(existing_entry->val);
	existing_entry->val = env_value;
}

static void	upsert_builtin_env_entry(char *argument,
		t_data **shell_state, int append_mode)
{
	char			*env_key;
	char			*env_value;
	int				assign_index;
	t_builtin_envp	*existing_entry;
	t_builtin_envp	*builtin_env_list;

	env_value = NULL;
	builtin_env_list = (*shell_state)->builtin_envp;
	assign_index = 0;
	env_key = extract_builtin_env_key(argument, &assign_index);
	if (env_key == NULL)
		return ;
	existing_entry = ft_getbuiltin_envp(*shell_state, env_key);
	env_value = build_export_value(argument, assign_index, append_mode);
	if (existing_entry != NULL)
	{
		existing_entry->equal = ft_haschar(argument, '=');
		merge_existing_export_key(existing_entry, env_value, env_key, append_mode);
	}
	else
	{
		existing_entry = ft_new_builtin_envp(env_key, env_value);
		existing_entry->equal = ft_haschar(argument, '=');
		ft_add_builtin_envp_back(&builtin_env_list, existing_entry);
	}
}

static void	process_export_args(t_data **shell_state)
{
	int	i;
	int	append_mode;

	append_mode = 0;
	i = 1;
	while ((*shell_state)->exec->cmd[i])
	{
		if (ft_haschar((*shell_state)->exec->cmd[i], '+') && \
		ft_check_plus((*shell_state)->exec->cmd[i]))
			append_mode = 1;
		upsert_builtin_env_entry((*shell_state)->exec->cmd[i],
			shell_state, append_mode);
		i++;
		append_mode = 0;
	}
}

int	builtin_export(t_data *shell_state)
{
	int	status_code;

	if (!shell_state->exec->cmd[1])
		print_builtin_export_builtin_env(shell_state);
	status_code = validate_builtin_export_keys(shell_state->exec->cmd, ERR_EXPORT);
	process_export_args(&shell_state);
	if (status_code != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
