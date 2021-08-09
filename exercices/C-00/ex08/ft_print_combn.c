#include <unistd.h>

void	compare_nums(char *num, int length);
void	ft_print_combn(int n);
void	f_putchar(char c);

void	f_putchar(char c)
{
	write(1, &c, 1);
}

char	*num_to_chars(int num, char *num_chars)
{
	char	num_char;
	int		i;

	i = 0;
	while (num > 0)
	{
		num_char = (num % 10) + '0';
		num /= 10;
		num_chars[i] = num_char;
		i++;
	}
	return (num_chars);
}

void	compare_nums(char *num, int length)
{
	int		i;
	char	first;
	char	second;

	i = length - 1;
	while (i > 0)
	{
		first = num[i];
		second = num[i - 1];
		if (first >= second)
			return ;
		i--;
	}
	i = length - 1;
	while (i >= 0)
	{
		f_putchar(num[i]);
		i--;
	}
	if (num[length - 1] == '9' - (length - 1) && num[0] == '9')
		return ;
	write(1, ", ", 2);
}

int	should_it_stop(int size, int *num)
{
	if ((size == 9 && *num == 23456790))
	{
		*num = 123456788;
		return (0);
	}
	if ((size == 9 && *num > 123456789) || (size == 8 && *num > 23456789))
	{
		return (1);
	}
	return (0);
}

void	ft_print_combn(int n)
{
	char	num_chars[9];
	int		i;
	int		total;

	i = 0;
	while (i < 9)
	{
		num_chars[i] = '0';
		i++;
	}
	i = 1;
	total = 10;
	while (i < n)
	{
		total *= 10;
		i++;
	}
	i = 0;
	while (i < total)
	{
		if (should_it_stop(n, &i) != 0)
			return ;
		compare_nums(num_to_chars(i, num_chars), n);
		i++;
	}
}
