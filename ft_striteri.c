void	ft_striteri(char *s, void (f*)(unsigned int, char*))
{
	size_t	i;

	i = -1;
	while (s[++i])
		s[i] = f(i, &s[i]);
}
