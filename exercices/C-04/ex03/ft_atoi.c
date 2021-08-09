int	ft_atoi(char *str);
int	find_num(char *str);
int	ft_isnum(char c);

int	find_num(char *str)
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
	return (num);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	if (!ft_isnum(str[i]))
		return (-1);
	num = find_num(&str[i]);
	if (num < 0)
		return (-1);
	return (num);
}
