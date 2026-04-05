#include "../../incl/minishell.h"

int	builtin_env(t_data *shell_state)
{
	t_builtin_envp	*cursor_node;

	if (shell_state->exec->cmd[1])
	{
		print_error(ERR_ENV);
		return (EXIT_CMD_NOT_FOUND);
	}
	cursor_node = shell_state->builtin_envp;
	while (cursor_node != NULL)
	{
		if (cursor_node->key[0] && cursor_node->equal == 1)
		{
			printf("%s=%s\n", cursor_node->key, cursor_node->val);
		}
		cursor_node = cursor_node->next;
	}
	return (EXIT_SUCCESS);
}
