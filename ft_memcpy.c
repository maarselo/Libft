#include <stdio.h>
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

int	main(void) {
	char	array1[] = {'a', 'b', 'c', 'd', 'e'};
	char	array2[] = {'z', 'y', 'w', 'v', 'x'};

	for (int i = 0; i < 5; i++)
		printf("%c", array1[i]);

	printf("\n");
	ft_memcpy(array1, array2, 5);

	for (int i = 0; i < 5; i++)
		printf("%c", array1[i]);
	return 0;
}
