/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:13:21 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/05 18:24:06 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb)
		ptr[i++] = '\0';
	return (ptr);
}
