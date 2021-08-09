char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] != '\0')
		{	
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i - j]);
		if (j == 0)
			i++;
	}
	return (0);
}
