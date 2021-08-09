#include "ft_atoi.h"

long	find_num(char *str)
{
	long	i;
	long	j;
	long	k;
	long	num;
	long	pow;

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

t_atoi_res	ft_atoi(char *str)
{
	t_atoi_res	res;
	int			i;

	res.num = 0;
	res.sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_issign(str[i]) && !ft_isnum(str[i]))
	{
		res.num = -1;
		return (res);
	}
	while (ft_issign(str[i]))
		if (str[i++] == '-')
			res.sign *= -1;
	if (!ft_isnum(str[i]))
	{
		res.num = -1;
		return (res);
	}
	res.num = find_num(&str[i]);
	return (res);
}
