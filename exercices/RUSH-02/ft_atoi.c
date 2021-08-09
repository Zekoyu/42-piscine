#include "olivia.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

int	ft_atoi(char *str)
{
	int	i;
	int	pow;
	int	res;

	pow = 1;
	i = 0;
	if (!is_number(str[i]))
		return (-1);
	res = find_num(&(str[i]));
	return (res);
}
