#include "../../incl/minishell.h"

void	ft_append_token_back(t_token **lst, t_token *new)
{
	t_token	*cursor_node;

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
