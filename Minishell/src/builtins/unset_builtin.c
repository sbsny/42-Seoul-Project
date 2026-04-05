#include "../../incl/minishell.h"

static void	remove_builtin_env_node(t_data **shell_state,
		t_builtin_envp *target_node)
{
	t_builtin_envp	*cursor_node;

	cursor_node = (*shell_state)->builtin_envp;
	if (ft_strcmp(cursor_node->key, target_node->key) == 0)
	{
		(*shell_state)->builtin_envp = cursor_node->next;
		free(target_node->val);
		free(target_node->key);
		free(target_node);
		return ;
	}
	while (cursor_node->next)
	{
		if ((ft_strcmp(cursor_node->next->key, target_node->key) == 0))
		{
			cursor_node->next = cursor_node->next->next;
			free(target_node->key);
			free(target_node->val);
			free(target_node);
			break ;
		}
		cursor_node = cursor_node->next;
	}
}

static int	validate_export_identifier_chars(char *arg, int mode)
{
	int	j;

	j = 0;
	while (arg[j] && arg[j + 1])
	{
		j++;
		if (arg[j] == '='
			|| (arg[j] == '+' && arg[j + 1] == '='))
			break ;
		if (!ft_isalpha(arg[j]) && !ft_isdigit((int)arg[j]) && arg[j] != '_')
		{
			exec_error(mode, arg);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	validate_builtin_export_keys(char **arguments, int error_mode)
{
	int	i;
	int	j;
	int	error_count;

	i = 1;
	error_count = 0;
	while (arguments[i] != NULL)
	{
		j = 0;
		if (!ft_isalpha(arguments[i][j]) && arguments[i][j] != '_')
			error_count += exec_error(error_mode, arguments[i]);
		else
			error_count += validate_export_identifier_chars(arguments[i],
					error_mode);
		i++;
	}
	return (error_count);
}

static int	is_invalid_unset_identifier(char *identifier)
{
	int	char_index;

	if (!identifier)
		return (1);
	char_index = 0;
	if (!ft_isalpha(identifier[0]) && identifier[0] != '_')
		return (1);
	while (identifier[char_index])
	{
		if (!ft_isalpha(identifier[char_index])
			&& !ft_isdigit(identifier[char_index])
			&& identifier[char_index] != '_')
			return (1);
		char_index++;
	}
	return (0);
}

int	builtin_unset(t_data *shell_state)
{
	t_builtin_envp	*cursor_node;
	int				i;
	int				error_count;

	error_count = 0;
	i = 1;
	if (!shell_state->exec->cmd[1])
		return (EXIT_SUCCESS);
	while (shell_state->exec->cmd[i])
	{
		cursor_node = NULL;
		if (is_invalid_unset_identifier(shell_state->exec->cmd[i]) == EXIT_FAILURE)
		{
			error_count++;
			exec_error(ERR_UNSET, shell_state->exec->cmd[i]);
		}
		else
			cursor_node = ft_getbuiltin_envp(shell_state, shell_state->exec->cmd[i]);
		if (cursor_node != NULL)
			remove_builtin_env_node(&shell_state, cursor_node);
		i++;
	}
	if (error_count > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
