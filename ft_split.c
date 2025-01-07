/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:40 by mvillavi          #+#    #+#             */
/*   Updated: 2025/01/05 20:27:37 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static	int	ft_countw(char *s, int c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
		       i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;		
	}
	return (count);
}

static	size_t	ft_lenw(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *substr;
        size_t  s_len;

        if (!s)
                return (NULL);
        s_len = ft_strlen(s);
        if (start >= s_len)
                return (ft_strdup(""));
        if (start + len > s_len)
                len = s_len - start;
        substr = (char *)malloc(sizeof(char) * (len + 1));
        if (!substr)
                return (NULL);
        ft_strlcpy (substr, s + start, len + 1);
        return (substr);
}

static	char	**ft_free(int n, char **array)
{
	while (n >= 0)
		free(array[n--]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t		words;
	size_t		i;

	if (s == NULL)
		return (NULL);
	words = ft_countw((char *)s, c);
	ptr = (char **)malloc((ft_countw((char *)s, c) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s == c && *s)
			s++;
		ptr[i] = ft_substr((char *)s, 0, ft_lenw((char *)s, c));
		if (ptr[i] == NULL)
			return (ft_free(i, ptr));
		s += ft_lenw((char *)s, c);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

#include <stdio.h>

int main (void)
{
	char	array[]= "Hola me llamo MArcelo";
	char	**ptr = ft_split(array, ' ');
	for (int i = 0; i < ft_countw(array, ' '); i++)
		printf("%s", ptr[i]);
	free(ptr);
	return 0;
}
