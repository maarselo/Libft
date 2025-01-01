/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:13:21 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/01 21:28:16 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(size_t number, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (size == 0)
		return (malloc(0));
	ptr = (char *)malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	while (i < number)
		ptr[i++] = '\0';
	return (ptr);
}
