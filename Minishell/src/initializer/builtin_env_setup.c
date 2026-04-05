#include "../../incl/minishell.h"

static char	*extract_env_value(const char *env_entry)
{
	int		cursor;
	int		value_offset;
	int		value_len;
	char	*env_value;

	env_value = NULL;
	cursor = 0;
	while (env_entry[cursor] != '\0')
	{
		if (env_entry[cursor] == '=')
			value_offset = cursor + 1;
		cursor++;
	}
	value_len = cursor - value_offset;
	env_value = ft_calloc(value_len + 1, sizeof(char));
	if (!env_value)
		return (NULL);
	cursor = 0;
	while (env_entry[value_offset] != '\0')
		env_value[cursor++] = env_entry[value_offset++];
	env_value[cursor] = '\0';
	return (env_value);
}

static char	*extract_env_key(const char *env_entry)
{
	int		cursor;
	char	*env_key;

	env_key = NULL;
	cursor = 0;
	while (env_entry[cursor] != '=')
		cursor++;
	env_key = ft_calloc(cursor + 1, sizeof(char));
	if (!env_key)
		return (NULL);
	cursor = 0;
	while (env_entry[cursor] != '=')
	{
		env_key[cursor] = env_entry[cursor];
		cursor++;
	}
	env_key[cursor] = '\0';
	return (env_key);
}

static void	parse_builtin_env_entry(t_data *shell_state,
		char *env_entry, char **env_key, char **env_value)
{
	*env_key = extract_env_key(env_entry);
	if (!*env_key)
	{
		clear_builtin_env_list(shell_state);
		exit(EXIT_FAILURE);
	}
	*env_value = extract_env_value(env_entry);
	if (!*env_value)
	{
		free(*env_key);
		clear_builtin_env_list(shell_state);
		exit(EXIT_FAILURE);
	}
}

void	bootstrap_builtin_env_list(t_data *shell_state, char **builtin_env)
{
	t_builtin_envp	*cursor_node;
	int				entry_index;
	char			*env_key;
	char			*env_value;

	cursor_node = NULL;
	entry_index = 0;
	while (builtin_env[entry_index] != NULL)
	{
		parse_builtin_env_entry(shell_state, builtin_env[entry_index],
			&env_key, &env_value);
		cursor_node = ft_new_builtin_envp(env_key, env_value);
		if (!cursor_node)
		{
			clear_builtin_env_list(shell_state);
			exit(EXIT_FAILURE);
		}
		if (ft_strcmp(cursor_node->key, "HOME") == 0)
			shell_state->builtins->home = ft_strdup(cursor_node->val);
		cursor_node->equal = true;
		ft_add_builtin_envp_back(&shell_state->builtin_envp, cursor_node);
		entry_index++;
	}
}
