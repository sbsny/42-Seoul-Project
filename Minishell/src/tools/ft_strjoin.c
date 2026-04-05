#include "../../incl/minishell.h"

char	*ft_strjoin(char *buf, char *cursor_node)
{
	int		i;
	int		j;
	char	*join;

	if (!cursor_node)
		return (buf);
	join = malloc(sizeof(char) * ((ft_strlen(buf) + ft_strlen(cursor_node)) + 1));
	if (!join)
		return (NULL);
	i = 0;
	if (buf != NULL)
	{
		while (buf[i] != '\0')
		{
			join[i] = buf[i];
			i++;
		}
		free(buf);
		buf = NULL;
	}
	j = 0;
	while (cursor_node[j] != '\0')
		join[i++] = cursor_node[j++];
	join[i] = '\0';
	return (join);
}
