#include "../../incl/minishell.h"

int	count_cmd_word_tokens(t_data *shell_state)
{
	t_token	*cursor_node;
	int		i;

	cursor_node = shell_state->tokens;
	if (!cursor_node)
		return (0);
	i = 0;
	while (cursor_node != NULL && cursor_node->flag != TOKEN_PIPE)
	{
		cursor_node = cursor_node->next;
		i++;
	}
	return (i);
}
