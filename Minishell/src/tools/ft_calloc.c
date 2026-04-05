#include "../../incl/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size > 0 && (SIZE_MAX / size) < count)
		return (NULL);
	total = size * count;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
