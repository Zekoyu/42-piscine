#include <unitsd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	if (nb > 0)
		c = '0' + (nb % 10);
	write(1, &c, 1);
}

void	print_board(t_skyscraper **board, int size)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < size)
	{
		while (col < size)
		{
			ft_putnbr(board[col][row].height);
			if (col != size - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
