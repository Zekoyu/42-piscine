#include <unistd.h>

void	ft_print_comb2(void);
void	print_nums(int num1, int num2);
void	print_char(char c);

void	print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char			num_chars[2];
	char			num_char;
	int				i;
	unsigned int	num;

	num_chars[0] = '0';
	num_chars[1] = '0';
	num = nb;
	i = 0;
	while (num > 0)
	{
		num_char = (num % 10) + '0';
		num /= 10;
		num_chars[i] = num_char;
		i++;
	}
	i = 1;
	while (i >= 0)
	{
		print_char(num_chars[i]);
		i--;
	}
}

void	print_nums(int num1, int num2)
{
	ft_putnbr(num1);
	print_char(' ');
	ft_putnbr(num2);
	if (!(num1 == 98 && num2 == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 < 99)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			if (num2 > num1)
			{
				print_nums(num1, num2);
			}
			num2++;
		}
		num1++;
	}
}
