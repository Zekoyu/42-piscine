#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write (1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
