#include "../../incl/minishell.h"

void	print_builtin_export_builtin_env(t_data *shell_state)
{
	t_builtin_envp	*cursor_node;

	cursor_node = shell_state->builtin_envp;
	while (cursor_node)
	{
		if (cursor_node->key[0])
		{
			if (ft_strlen(cursor_node->val) != 0)
				printf("declare -x %s=\"%s\"\n", cursor_node->key, cursor_node->val);
			else if (cursor_node->equal == false)
				printf("declare -x %s\n", cursor_node->key);
			else if (cursor_node->equal == true)
				printf("declare -x %s=\"\"\n", cursor_node->key);
		}
		cursor_node = cursor_node->next;
	}
}

static int	is_valid_export_identifier(char *identifier)
{
	int	i;

	i = 1;
	if (!identifier || ft_strlen(identifier) < 1)
		return (0);
	if (identifier[0] != '_' && !ft_isalpha(identifier[0]))
		return (0);
	while (identifier[i])
	{
		if ((identifier[i] == '=' && i != 0) || (identifier[i] == '+' \
		&& identifier[i + 1] && identifier[i + 1] == '=' && i != 0))
			return (1);
		else if (!ft_isalpha(identifier[i]) && !ft_isdigit(identifier[i]) \
		&& identifier[i] != '_' && i != 0)
			return (0);
		i++;
	}
	return (1);
}

char	*extract_builtin_env_key(char *argument, int *delimiter_index)
{
	char	*env_key;

	env_key = NULL;
	if (!is_valid_export_identifier(argument))
		return (env_key);
	while (argument[*delimiter_index])
	{
		if (argument[*delimiter_index] == '=' || argument[*delimiter_index] == '+')
			break ;
		(*delimiter_index)++;
	}
	env_key = malloc(sizeof(char) * ((*delimiter_index) + 1));
	env_key[(*delimiter_index)] = '\0';
	*delimiter_index = 0;
	while (argument[*delimiter_index])
	{
		if (argument[*delimiter_index] == '='
			|| argument[*delimiter_index] == '+')
			break ;
		env_key[*delimiter_index] = argument[*delimiter_index];
		(*delimiter_index)++;
	}
	return (env_key);
}
