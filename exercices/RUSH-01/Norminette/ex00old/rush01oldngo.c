#include <stdlib.h>
#include <unistd.h>
#ifndef HELPERSTRU_H

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// Count the total count of numbers in the given string (separated by spaces)
//If it is a number and we're not currently 
//in a number, increment total and set currently number to true
// Else if current char is not a number
int	count_nums(char *str)
{
	int	total;
	int	curr_is_num;

	total = 0;
	curr_is_num = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && !curr_is_num)
		{
			total++;
			curr_is_num = 1;
		}
		else if (*str < '0' || *str > '9')
		{
			curr_is_num = 0;
		}
		str++;
	}
	return (total);
}

// If starting char is not a number, invalid string
// If char is not a space and not a number, invalid string
// If more than one space separating number, invalid string
int	is_valid_split_num_input(char *str)
{
	if (*str < '0' || *str > '9')
		return (0);
	while (*str)
	{
		if (*str != ' ' && (*str < '0' || *str > '9'))
			return (0);
		if (*str == ' ' && (*(str + 1) < '0' || *(str + 1) > '9'))
			return (0);
		str++;
	}
	return (1);
}

// If char is not a space and not a number, invalid string
int	is_valid_num_input(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

// Remove the given number from possibilities; ex:
// want to remove between 3 and 5, so remove list[2], list[3], list[4]
void	remove_possibilities(t_skyscraper skyscraper, int rm_start, int rm_end)
{
	int	i;

	i = rm_start;
	while (i <= rm_end)
	{
		skyscraper.possibilities[i - 1] = 0;
		i++;
	}
}

// For each top viewpoint
// If pov = n; we know the whole column should be increasing from 1 to N
// If pov = 1, the skyscraper right in front should N tall;
// For all values between 1 and N, apply the formula (N - c + 2 + d)
// We can exclude heights for skyscrapers up to clue value - 1
// Same for bottom viewpoints
// Starts from the bottom of the column
// Same for left viewpoints
// Same for right viewpoints
// Starts from the right of the row
// If skyscraper already has a fixed height
// Set each nearby cell as constrained
// For each skyscraper in the same col
// Remove this possible value
// For each skyscraper in the same row
// Remove this possible value
void	constraint_propagation(t_skyscraper **board, int size)
{
	for (int col = 0; col < size; col++)
	{
		for (int row = 0; row < size; row++)
		{
			int value = board[col][row].height;
			if (value != 0)
			{
				for (int i = 0; i < size; i++)
				{
					board[col][i].possibilities[value - 1] = 0;
				}
				for (int i = 0; i < size; i++)
				{
					board[i][row].possibilities[value - 1] = 0;
				}
			}
		}
	}
}

int	*get_possible_values(t_skyscraper skyscraper, int size)
{
	int	count;
	int	*result;

	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (skyscraper.possibilities[i] != 0)
		{
			count++;
		}
	}
	result = malloc (sizeof (int) * count + 1);
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (skyscraper.possibilities[i] != 0)
		{
			result[j] = skyscraper.possibilities[i];
			j++;
		}
	}
	result[count] = -1;
	return (result);
}

int	value_in_array(int *values_arr, int values_arr_size, int value)
{
	for (int i = 0; i < values_arr_size; i++)
	{
		if (values_arr[i] == value)
			return (1);
	}
	return (0);
}

// Init array
// Check column (if not unique return 0)
// If value not initialized, dont consider it
// Reset array
// Check row (if not unique return 0)
// If value not initialized, dont consider it
// If nothing duplicated, return OK;
int	check_unique_boxes(t_skyscraper **board, int size, int col, int row)
{
	int *numbers = malloc(sizeof (int) * size);

	for (int i = 0; i < size; i++)
		numbers[i] = 0;
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (board[col][i].height == 0)
			continue ;
		if (value_in_array(numbers, size, board[col][i].height))
			return (0);
		else
			numbers[j++] = board[col][i].height;
	}
	for (int i = 0; i < size; i++)
		numbers[i] = 0;
	j = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (board[i][row].height == 0)
			continue ;
		if (value_in_array(numbers, size, board[i][row].height))
			return (0);
		else
			numbers[j++] = board[i][row].height;
	}
	free(numbers);
	return (1);
}

int	col_is_full(t_skyscraper **board, int size, int column)
{
	for (int i = 0; i < size; i++)
	{
		if (board[column][i].height == 0)
			return (0);
	}
	return (1);
}

int	row_is_full(t_skyscraper **board, int size, int row)
{
	for (int i = 0; i < size; i++)
	{
		if (board[i][row].height == 0)
			return (0);
	}
	return (1);
}

// If everything is complete, print & stop
int test_backtrack(t_viewpoints viewpoints, t_skyscraper **board, int size, int col, int row)
{
	if (col == size && row == 0)
	{
		print_possibilities(board, size);
		return (1);
	}
	t_skyscraper *skyscraper = &(board[col][row]);
	int *possible_values = get_possible_values(*skyscraper, size);

	if(ITERATIONS % 10000 == 0)
	{
		printf("====== Iteration %d ========\n", ITERATIONS);
		print_board(board, size);
		ITERATIONS++;
	}

	if (skyscraper -> height > 0)
	{
		ITERATIONS++;
		if (row == size - 1)
		{
			if(test_backtrack(viewpoints, board, size, col + 1, 0) == 1)
				return (1);
		}
		else
		{
			if (test_backtrack(viewpoints, board, size, col, row + 1) == 1)
				return (1);
		}
	}
	else
	{
		for (int i = 0; possible_values[i] != -1; i++)
		{
			ITERATIONS++;
			skyscraper -> height = possible_values[i];

			if (check_from_all_sides(viewpoints, board, size, col, row))
			{
				if (row == size - 1)
				{
					if(test_backtrack(viewpoints, board, size, col + 1, 0) == 1)
						return (1);
				}
				else
				{
					if (test_backtrack(viewpoints, board, size, col, row + 1) == 1)
						return (1);
				}
			}
		}
	}
	if (!(skyscraper -> fixed))
		skyscraper -> height = 0;
	return (0);
}
