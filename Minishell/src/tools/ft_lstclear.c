#include "../../incl/minishell.h"

void	ft_lstclear(t_builtin_envp **lst)
{
	t_builtin_envp	*cursor_node;

	if ((!lst) || (!*lst))
		return ;
	while (*lst)
	{
		cursor_node = (*lst)->next;
		free(*lst);
		*lst = cursor_node;
	}
	*lst = NULL;
}
