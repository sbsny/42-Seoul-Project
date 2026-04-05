#include "../incl/minishell.h"

void	clear_heredoc_files(t_data *shell_state)
{
	int i;

	if (shell_state->fd->hdoc == NULL)
		return ;
	i = 0;
	while (shell_state->fd->hdoc[i] != NULL)
	{
		unlink(shell_state->fd->hdoc[i]);
		free(shell_state->fd->hdoc[i]);
		shell_state->fd->hdoc[i] = NULL;
		i++;
	}
	free(shell_state->fd->hdoc);
	shell_state->fd->hdoc = NULL;
}

void	clear_token_stream(t_data *shell_state)
{
	t_token *del;

	del = NULL;
	if (shell_state->tokens == NULL)
		return ;
	while (shell_state->tokens != NULL)
	{
		del = shell_state->tokens;
		shell_state->tokens = shell_state->tokens->next;
		free(del->content);
		del->content = NULL;
		free(del);
		del = NULL;
	}
	shell_state->tokens = NULL;
}

void	clear_builtin_table(t_data *shell_state)
{
	int i;

	i = 0;
	while (i < BUILTIN_COUNT && shell_state->builtins->names[i] != NULL)
	{
		free(shell_state->builtins->names[i]);
		shell_state->builtins->names[i] = NULL;
		i++;
	}
	free(shell_state->builtins);
}

void	clear_builtin_env_list(t_data *shell_state)
{
	t_builtin_envp	*cursor_node;

	cursor_node = shell_state->builtin_envp;
	while (cursor_node != NULL)
	{
		free(cursor_node->key);
		cursor_node->key = NULL;
		free(cursor_node->val);
		cursor_node->val = NULL;
		cursor_node = cursor_node->next;
	}
	ft_lstclear(&shell_state->builtin_envp);
	shell_state->builtin_envp = NULL;
}

void	shutdown_shell(t_data *shell_state)
{
	free(shell_state->builtins->home);
	clear_builtin_table(shell_state);
	clear_builtin_env_list(shell_state);
	clear_token_stream(shell_state);
	free(shell_state->sep);
	free(shell_state->redir);
	close(shell_state->fd->std_in);
	close(shell_state->fd->std_out);
	free(shell_state->fd);
	free(shell_state->exec);
}
