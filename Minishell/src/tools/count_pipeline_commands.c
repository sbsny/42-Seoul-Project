#include "../../incl/minishell.h"

int	count_pipeline_cmds(t_data *shell_state)
{
	t_token	*cursor_node;
	int		i;

	cursor_node = shell_state->tokens;
	i = 1;
	while (cursor_node != NULL)
	{
		if (cursor_node->flag == TOKEN_PIPE)
			i++;
		cursor_node = cursor_node->next;
	}
	return (i);
}
