/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:48:58 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/05 20:32:17 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
