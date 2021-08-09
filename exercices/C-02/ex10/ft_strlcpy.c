int	ft_strlcpy(char *dest, char *src, unsigned int n);
int	get_str_len(char *str);

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (get_str_len(src));
	while (i < n - 1)
	{
		if (src[i] == '\0')
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
			return (get_str_len(src));
		}
		else
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (get_str_len(src));
}
