#include "../../incl/minishell.h"

int	ft_lstsize(t_builtin_envp *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
