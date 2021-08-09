int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	else if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	else
		return (0);
}
