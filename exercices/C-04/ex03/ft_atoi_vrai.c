int	ft_atoi(char *str);
int	find_num(char *str);
int	ft_isspace(char c);
int	ft_isnum(char c);
int	ft_issign(char c);

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

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_issign(str[i]) && !ft_isnum(str[i]))
		return (num);
	while (ft_issign(str[i]))
	{
		if (str[i] == '+')
			sign *= 1;
		else if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isnum(str[i]))
		return (num);
	num = find_num(&str[i]);
	return (num * sign);
}
