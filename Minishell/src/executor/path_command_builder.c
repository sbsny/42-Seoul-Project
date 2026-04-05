#include "../../incl/minishell.h"

static char	**add_cmd_and_path(t_data *shell_state, char **cmd, int words)
{
	int		word_index;
	t_token	*cursor;
	char	**path;

	path = ft_split(shell_state->tokens->content, CHAR_SLASH);
	if (!path)
		return (NULL);
	shell_state->exec->path = ft_strdup(shell_state->tokens->content);
	if (!shell_state->exec->path)
		return (NULL);
	cmd[0] = ft_strdup(path[ft_splitlen(path) - 1]);
	if (!cmd[0])
		return (NULL);
	word_index = 1;
	cursor = shell_state->tokens->next;
	while (word_index < words)
	{
		cmd[word_index] = ft_strdup(cursor->content);
		if (!cmd[word_index])
			return (NULL);
		cursor = cursor->next;
		word_index++;
	}
	ft_cleansplit(path);
	return (cmd);
}

char	**extract_cmd_from_path(t_data *shell_state)
{
	char	**cmd;
	int		words;

	words = count_cmd_word_tokens(shell_state);
	if (words == 0)
		return (NULL);
	cmd = malloc(sizeof(char *) * (words + 1));
	if (!cmd)
		return (NULL);
	cmd[words] = NULL;
	cmd = add_cmd_and_path(shell_state, cmd, words);
	return (cmd);
}
