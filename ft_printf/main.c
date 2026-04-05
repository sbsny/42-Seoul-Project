#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%c \n", 'a');
	ft_printf("%c \n", 'a');
	printf("%s \n", "abcd");
	ft_printf("%s \n", "abcd");
	printf("%p \n", (void *)0);
	ft_printf("%p \n", (void *)0);
	printf("%d %i \n", 1, 1);
	ft_printf("%d %i \n", 1, 1);
	printf("%u \n", 34);
	ft_printf("%u \n", 34);
	printf("%x %X \n", 77, 77);
	ft_printf("%x %X \n", 77, 77);
	printf("%% \n");
	ft_printf("%% \n");

	return 0;
}