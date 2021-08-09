#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	set_pos_num(long *num, long value)
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

void	ft_putnbr(long nb)
{
	char			num_chars[10];
	char			num_char;
	long			i;
	long			num;

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
