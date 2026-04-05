#include "../../incl/minishell.h"

char	*ft_strtrim(char *str, char delim)
{
	int		i;
	int		start;
	int		end;
	char	*trim;

	if (!str)
		return (NULL);
	start = 0;
	while ((str[start] != '\0') && (str[start] == delim))
		start++;
	end = (int)ft_strlen(str);
	while ((end > start) && (str[end] == delim))
		end--;
	trim = malloc(sizeof(char) * (end - start + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (start < end)
		trim[i++] = str[start++];
	trim[i] = '\0';
	free(str);
	return (trim);
}
