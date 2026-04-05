#include "../../incl/minishell.h"

int	builtin_pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	if (!path)
	{
		perror(NULL);
		return (EXIT_CMD_NOT_FOUND);
	}
	printf("%s\n", path);
	free(path);
	return (EXIT_SUCCESS);
}
