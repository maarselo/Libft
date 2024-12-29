#include "libft.h"

char	*ft_calloc(size_t number, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	while (i < number)
		ptr[i++] = '\0';
	return (ptr);
}
