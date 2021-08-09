#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	print_hex_address(uintptr_t addr);
void	print_hex_char(unsigned char c);
void	print_chars(char *str, int start, int end, unsigned int size);
void	print_hexs(char *str, int start, int end, unsigned int size);

void	print_hex_address(uintptr_t dec_addr)
{
	char	hex_addr[16];
	int		remainder;
	int		i;
	char	hex;

	i = 16;
	while (i >= 0)
	{
		i--;
		remainder = dec_addr % 16;
		if (remainder <= 9)
			hex = remainder + 48;
		else
			hex = remainder + 87;
		dec_addr /= 16;
		hex_addr[i] = hex;
	}
	i = 0;
	while (i < 16)
	{
		write(1, &hex_addr[i], 1);
		i++;
	}
	write(1, ": ", 2);
}

void	print_hex_char(unsigned char c)
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
	write(1, &hex_two_digits[1], 1);
	write(1, &hex_two_digits[0], 1);
}

void	print_chars(char *str, int start, int end, unsigned int size)
{
	int	i;

	i = start;
	while (i < end)
	{
		if ((unsigned int) i < size)
		{
			if (str[i] < 32 || str[i] >= 127)
				write(1, ".", 1);
			else
				write(1, &str[i], 1);
		}
		i++;
	}
}

void	print_hexs(char *str, int start, int end, unsigned int size)
{
	int	i;

	i = start;
	while (i < end)
	{
		if ((unsigned int) i < size)
			print_hex_char(str[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int			i;
	int			j;
	int			total_lines;
	uintptr_t	dec_address;
	char		*value_chars;

	total_lines = size / 16;
	if (size % 16 > 0)
		total_lines++;
	value_chars = addr;
	i = 0;
	while (i < total_lines)
	{
		j = i * 16;
		dec_address = (uintptr_t) & addr[i * 16];
		print_hex_address(dec_address);
		print_hexs(value_chars, (i * 16), ((i + 1) * 16), size);
		print_chars(value_chars, i * 16, (i + 1) * 16, size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
