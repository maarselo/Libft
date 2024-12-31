
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static	char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strdup(char *str)
{
	char	*ptr;

	ptr = (char *)malloc(strlen(str) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, str);
	return (ptr);
}

int	main(void)
{
	char	array1[] = "Hola alejandra";
	char	*ptr = ft_strdup(array1);

	printf("%s\n", array1);
	printf("%s\n", ptr);
	return 0;
}
