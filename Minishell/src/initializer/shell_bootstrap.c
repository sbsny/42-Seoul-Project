#include "../../incl/minishell.h"

static void	reset_old_builtin_pwd(t_data *shell_state)
{
	t_builtin_envp	*cursor_node;

	cursor_node = shell_state->builtin_envp;
	while (cursor_node != NULL)
	{
		if (ft_strcmp(cursor_node->key, "OLDPWD") == 0)
			break ;
		cursor_node = cursor_node->next;
	}
	if (cursor_node != NULL && ft_strcmp(cursor_node->key, "OLDPWD") == 0)
	{
		free(cursor_node->val);
		cursor_node->val = ft_strdup("");
	}
}

static void	reset_runtime_flags(t_data *shell_state)
{
	shell_state->exit_minishell = false;
	shell_state->lex_error = false;
	shell_state->parse_error = false;
	shell_state->exec_error = false;
}

void	reset_exec_state(t_data *shell_state)
{
	shell_state->exec->cmd = NULL;
	shell_state->exec->path = NULL;
	shell_state->exec->cmd_num = 1;
	shell_state->exec->last_cmd = 0;
	shell_state->pid = 0;
}

void	bootstrap_shell(t_data *shell_state, char **builtin_envp)
{
	g_exit_code = 0;
	shell_state->pipe[0] = -1;
	shell_state->pipe[1] = -1;
	shell_state->fd = malloc(sizeof(t_fd));
	if (!shell_state->fd)
		return ;
	reset_fd_state(shell_state);
	backup_stdio_fds(shell_state);
	shell_state->exec = malloc(sizeof(t_exec));
	reset_exec_state(shell_state);
	reset_runtime_flags(shell_state);
	allocate_shell_context(shell_state);
	shell_state->builtin_env = builtin_envp;
	bootstrap_builtin_env_list(shell_state, builtin_envp);
	reset_old_builtin_pwd(shell_state);
}
