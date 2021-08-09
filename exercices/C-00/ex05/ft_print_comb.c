#include <unistd.h>

void	ft_print_comb(void);
void	ft_putchars(char a, char b, char c);

void	ft_putchars(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{	
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{	
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchars(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
