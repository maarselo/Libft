/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:15:33 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/07 18:01:16 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	s_len = strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (s1[start] && strchr(set, s1[start]))
		start++;
	end = strlen(s1);
	while (s1[end] && strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start));
}

int	main(void)
{
	char	array[]= "hoolaho";
	char	*ptr = ft_strtrim(array, "ho");
	printf("%s", ptr);
	return 0;
}
