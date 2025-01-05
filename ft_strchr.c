/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:50:33 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/05 18:17:35 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*while (c != s[i] && s[i] != '\0')
		i++;
	if (c == s[i])
		return (&s[i]);*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || s[i] == '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
