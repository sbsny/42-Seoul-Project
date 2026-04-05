#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("main1.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	printf("%s", str);
	free(str);
	close(fd);
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}