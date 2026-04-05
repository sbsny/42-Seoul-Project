#include "../../incl/minishell.h"

static char	*assign_path(char **paths, char *cmd)
{
	int		path_index;
	char	*path;
	char	*path_with_slash;
	char	*slash;

	path = NULL;
	path_with_slash = NULL;
	slash = ft_strdup("/");
	path_index = 0;
	while (paths[path_index] != NULL)
	{
		path = ft_strdup(paths[path_index]);
		path_with_slash = ft_strjoin(path, slash);
		path = ft_strjoin(path_with_slash, cmd);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		path_index++;
	}
	free(slash);
	return (path);
}

static char	**get_valid_paths(t_data *shell_state)
{
	t_builtin_envp	*builtin_envp;
	char	*path;
	char	**valid_paths;

	builtin_envp = shell_state->builtin_envp;
	path = NULL;
	while (builtin_envp != NULL)
	{
		if (ft_strcmp("PATH", builtin_envp->key) == 0)
		{
			path = builtin_envp->val;
			break ;
		}
		builtin_envp = builtin_envp->next;
	}
	if (!path)
		path = ft_strdup("./");
	valid_paths = ft_split(path, ':');
	if (!valid_paths)
		return (NULL);
	if (ft_strcmp(path, "./") == 0)
		free(path);
	return (valid_paths);
}

char	*get_cmd_path(t_data *shell_state)
{
	char	*cmd;
	char	**valid_paths;
	char	*cmd_path;

	cmd = shell_state->exec->cmd[0];
	valid_paths = get_valid_paths(shell_state);
	if (!valid_paths)
	{
		perror(NULL);
		shell_state->exec_error = true;
		return (NULL);
	}
	cmd_path = assign_path(valid_paths, cmd);
	ft_cleansplit(valid_paths);
	return (cmd_path);
}

char	**create_cmd(t_data *shell_state, char **cmd, int words)
{
	int		word_index;
	t_token	*cursor;

	cursor = shell_state->tokens;
	word_index = 0;
	while (word_index < words)
	{
		cmd[word_index] = ft_strdup(cursor->content);
		if (!cmd[word_index])
			return (NULL);
		cursor = cursor->next;
		word_index++;
	}
	cmd[words] = NULL;
	return (cmd);
}

char	**get_cmd(t_data *shell_state)
{
	char	**cmd;
	int		words;

	words = count_cmd_word_tokens(shell_state);
	if (words == 0)
		return (NULL);
	cmd = malloc(sizeof(char *) * (words + 1));
	if (!cmd)
	{
		perror(NULL);
		shell_state->exec_error = true;
		return (NULL);
	}
	cmd = create_cmd(shell_state, cmd, words);
	return (cmd);
}
