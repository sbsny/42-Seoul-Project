#include "../../incl/minishell.h"

static char	*join_tmp_to_buf(char *buf, char *cursor_node)
{
	int		i;
	int		j;
	char	*join;

	join = malloc(sizeof(char) * ((ft_strlen(buf) + ft_strlen(cursor_node)) + 1));
	if (!join)
	{
		free(cursor_node);
		return (NULL);
	}
	i = 0;
	while (buf[i] != '\0')
	{
		join[i] = buf[i];
		i++;
	}
	j = 0;
	while (cursor_node[j] != '\0')
		join[i++] = cursor_node[j++];
	join[i] = '\0';
	free(cursor_node);
	return (join);
}

char	*ft_join_tilde(char *buf, char *cursor_node, int flag)
{
	char	*join;

	if (flag == 1)
	{
		join = ft_strdup(buf);
		free(cursor_node);
		return (join);
	}
	else
		join = join_tmp_to_buf(buf, cursor_node);
	return (join);
}
