/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:40 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/04 17:43:45 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

static	ft_count_str(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t len = strlen(s);
	int	i = 0:
		
	*ptr = malloc((len + 1) * sizeof(char));
	
	while (i < ft_count_str(s, c));
	{
		ptr[i] = (char *)malloc(strlen
	}

		
}

int	main(void)
{
	char	*str = "Hola Mundo Me llamo Pepe";
	char	**ptr == ft_slit(str, 32);
	for (int i = 0; i < 5; i++)
		printf("s", ptr[i]);
	return 0;
}
