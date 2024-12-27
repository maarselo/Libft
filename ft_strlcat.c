/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:28:40 by mvillavi          #+#    #+#             */
/*   Updated: 2024/12/26 19:33:06 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta funcion a diferencia de strncat, que concatena el numero de caracteres
pasas el size de buffer dest, una manera de que siempre se ponga el nulo, y el
y el valor de retorno es la suma de caracteres, de ambas str.*/

#include "libft.h"

int	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = len_dest;
	if (size <= len_dest)
		return (len_dest + len_src);
	while (i < size - 1 && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (len_dest + len_src);
}
