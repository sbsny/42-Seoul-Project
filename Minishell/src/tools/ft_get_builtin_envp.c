#include "../../incl/minishell.h"

t_builtin_envp	*ft_getbuiltin_envp(t_data *shell_state, char *find)
{
	t_builtin_envp	*cursor_node;

	cursor_node = shell_state->builtin_envp;
	if (!cursor_node)
		return (NULL);
	while (cursor_node)
	{
		if (ft_strcmp(cursor_node->key, find) == 0)
			return (cursor_node);
		cursor_node = cursor_node->next;
	}
	return (NULL);
}
