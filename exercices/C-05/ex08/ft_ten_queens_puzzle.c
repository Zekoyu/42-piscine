#include <unistd.h>

// 				=-=-=-=-= Is Safe =-=-=-=-=-
//
// Check if given position (column, row) is safe in given board:
// > Check if any queen on the same row
// > Check if any queen on the same / diagonal (check every row++ and column--)
// > Check if any queen on the same \ diagonal (check every row-- and column--)

int	is_safe(int board[][10], int column, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < column)
	{
		if (board[i][row] == 1)
			return (0);
		i++;
	}
	i = column;
	j = row;
	while (--i >= 0 && --j >= 0)
	{
		if (board[i][j] == 1)
			return (0);
	}
	i = column;
	j = row;
	while (--i >= 0 && ++j < 10)
	{
		if (board[i][j] == 1)
			return (0);
	}	
	return (1);
}

// 	=-=-=-=-= Put result =-=-=-=-=-
// 
// Simply prints the position of queens (represented as 1) in each column
// Position + '0' to get the number as char representation

void	put_result(int board[][10])
{
	int		i;
	int		j;
	char	char_num;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j] == 1)
			{
				char_num = j + '0';
				write(1, &char_num, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

// 	=-=-=-=-= Place queen (recursive) =-=-=-=-=-
// 
// For every position in the current column, check if the position is safe
// If it is, place a queen and go to next column
// If column reach 10 => print the board
// Else simply just go back to the previous column and change the pos 
// until every position has been tried
// Since the board is always displayed when it is full, 
// we reset the board and try the next number
// If is has not been succesfull, it can continue

void	place_queen(int board[][10], int column, int *results_count)
{
	int	row;

	if (column == 10)
	{
		put_result(board);
		(*results_count) += 1;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, column, row))
		{
			board[column][row] = 1;
			place_queen(board, column + 1, results_count);
			board[column][row] = 0;
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	results_count;
	int	i;
	int	j;

	results_count = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	place_queen(board, 0, &results_count);
	return (results_count);
}
