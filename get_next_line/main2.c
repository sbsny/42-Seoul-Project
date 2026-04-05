
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str1;
	char	*str2;

	fd1 = open("main1.txt", O_RDONLY);
	fd2 = open("main2.txt", O_RDONLY);
	printf("fd1: %d\n", fd1);
	printf("fd2: %d\n", fd2);

	str1 = get_next_line(fd1);
	printf("%s", str1);
	str2 = get_next_line(fd2);
	printf("%s", str2);

	free(str1);
	free(str2);

	str1 = get_next_line(fd1);
	printf("%s", str1);
	str2 = get_next_line(fd2);
	printf("%s", str2);

	free(str1);
	free(str2);
	close(fd1);
	close(fd2);
	return (0);
}