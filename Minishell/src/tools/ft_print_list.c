#include "../../incl/minishell.h"

int	print_list(t_token *shell_state)
{
	t_token	*cursor_node;
	int		len;

	len = 0;
	cursor_node = shell_state;
	while (cursor_node != NULL)
	{
		len++;
		printf("%s\nflag = %i\n", cursor_node->content, cursor_node->flag);
		if (cursor_node->join)
			printf("join = true\n");
		else
			printf("join = false\n");
		cursor_node = cursor_node->next;
	}
	return (len);
}
