/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:50:33 by mvillavi          #+#    #+#             */
/*   Updated: 2024/12/30 22:38:51 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*while (c != s[i] && s[i] != '\0')
		i++;
	if (c == s[i])
		return (&s[i]);*/

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || s[i] == '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
