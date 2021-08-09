#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	set_pos_num(unsigned int *num, int value);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	set_pos_num(unsigned int *num, int value)
{
	if (value < 0)
	{
		*num = -value;
		ft_putchar('-');
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
		ft_putchar('0');
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
		ft_putchar(num_chars[i]);
		i--;
	}
}
