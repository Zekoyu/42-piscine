#include <unistd.h>
#include "olivia.h"

int	is_number_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_number(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

void	set_pos_num(unsigned int *num, int value)
{
	if (value < 0)
	{
		*num = -value;
		write(1, "-", 1);
	}
	else
	{
		*num = value;
	}
}

void	ft_putnbr(int nb)
{
	char			num_chars[10];
	char			num_char;
	int				i;
	unsigned int	num;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	set_pos_num(&num, nb);
	i = 0;
	while (num > 0)
	{
		num_char = (num % 10) + '0';
		num /= 10;
		num_chars[i] = num_char;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &num_chars[i], 1);
		i--;
	}
}
