#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)to;
	src = (unsigned char *)from;
	while (numBytes --)
		*dest++ = *src++;
	return (to);
}
