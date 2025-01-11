/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:39:12 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/11 17:06:22 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < count - 1)
		i++;
	return (s1[i] - s2[i]);
}
*/

int	ft_strncmp(const char *s1,const char *s2, size_t count)
{
	if (count == 0)
		return (0);
	while (--count > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
