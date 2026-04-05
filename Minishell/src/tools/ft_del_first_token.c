#include "../../incl/minishell.h"

void	ft_del_first_token(t_data **shell_state)
{
	t_token	*cursor_node;

	cursor_node = (*shell_state)->tokens;
	if (!cursor_node)
		return ;
	(*shell_state)->tokens = (*shell_state)->tokens->next;
	free(cursor_node->content);
	cursor_node->content = NULL;
	free(cursor_node);
}
