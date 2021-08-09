#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	print_hex(unsigned char c);
int		is_printable(char c);

void	print_hex(unsigned char c)
{
	int		i;
	char	hex;
	char	remainder;
	char	hex_two_digits[2];

	hex_two_digits[0] = '0';
	hex_two_digits[1] = '0';
	i = 0;
	while (c > 0)
	{
		remainder = c % 16;
		if (remainder <= 9)
			hex = remainder + 48;
		else
			hex = remainder + 87;
		c /= 16;
		hex_two_digits[i] = hex;
		i++;
	}
	write(1, "\\", 1);
	write(1, &hex_two_digits[1], 1);
	write(1, &hex_two_digits[0], 1);
}

int	is_printable(char c)
{
	if (c < 32 || c >= 127)
		return (0);
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			print_hex(str[i]);
		}
		i++;
	}
}
