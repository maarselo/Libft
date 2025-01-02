#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	end = strlen(s1) - 1;
	while (s1[start] && strchr(set, s1[start]) != NULL)
		start++;
	while (s1[end] && strchr(set, s1[end]) != NULL)
		end--;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ptr == NULL)
		return (NULL);
	size_t	i;

	i = 0;
	while (end > start)
		ptr[i++] = s1[start++];
	*ptr = '\0';	
	return (ptr);
}

int	main(void)
{
	char	array1[] = "ALejandraSubnormal";
	char	array2[] = "l";
	char	*ptr = ft_strtrim(array1, array2);

	printf("%s", ptr);
	return 0;
}
