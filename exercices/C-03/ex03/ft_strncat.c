char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char*src, unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && (unsigned int) j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
