/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:27:18 by mvillavi          #+#    #+#             */
/*   Updated: 2024/12/31 00:52:53 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	total_len;
	char	*ptr;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc((total_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s2)
	{
		while (*s1)
			ptr[i++] = *s1++;
		ptr[i++] = *s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}
