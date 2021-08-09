int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	k;
	int	num;
	int	pow;

	num = 0;
	i = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i++;
	while (--i >= 0)
	{
		pow = 1;
		k = 0;
		while (k < j)
		{
			pow *= 10;
			k++;
		}
		num += (str[i] - 48) * pow;
		j++;
	}
	if (num == 0)
		return (-1);
	return (num);
}
