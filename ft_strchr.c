#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	char	*caracter;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (caracter = &str[i]);
		i++;
	}
	return (NULL);
}
