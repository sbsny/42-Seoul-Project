#include "../../incl/minishell.h"

int	ft_splitlen(char **s)
{
	int	count;

	count = 0;
	while (s && s[count] && s[count][0])
		count++;
	return (count);
}
