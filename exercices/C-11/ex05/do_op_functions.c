#include "put_things.h"

void	add(int x, int y)
{
	ft_putnbr(x + y);
	ft_putstr("\n");
}

void	substract(int x, int y)
{
	ft_putnbr(x - y);
	ft_putstr("\n");
}

void	multiply(int x, int y)
{
	ft_putnbr(x * y);
	ft_putstr("\n");
}

void	divide(int x, int y)
{
	if (y == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	ft_putnbr(x / y);
	ft_putstr("\n");
}

void	modulo(int x, int y)
{
	if (y == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	ft_putnbr(x % y);
	ft_putstr("\n");
}
