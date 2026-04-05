#include "../../incl/minishell.h"

bool	ft_check_plus(char *s)
{
	int	i;

	i = 0;
	while (s[i + 1])
	{
		if (s[i] == '+' && s[i + 1] == '=')
			return (true);
		if (s[i] == '=')
			break ;
		i++;
	}
	return (false);
}
