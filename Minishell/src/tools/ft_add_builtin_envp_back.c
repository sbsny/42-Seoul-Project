#include "../../incl/minishell.h"

void	ft_add_builtin_envp_back(t_builtin_envp **lst, t_builtin_envp *new)
{
	t_builtin_envp	*cursor_node;

	cursor_node = NULL;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cursor_node = *lst;
	while (cursor_node->next != NULL)
		cursor_node = cursor_node->next;
	cursor_node->next = new;
}
