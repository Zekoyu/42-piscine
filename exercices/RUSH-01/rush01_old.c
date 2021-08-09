#include <stdlib.h>
#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	k;
	int	num;
	int	pow;

	num = 0;
	i = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i++;
	while (--i >= 0)
	{
		pow = 1;
		k = 0;
		while (k < j)
		{
			pow *= 10;
			k++;
		}
		num += (str[i] - 48) * pow;
		j++;
	}
	if (num == 0)
		return (-1);
	return (num);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	if (nb > 0)
		c = '0' + (nb % 10);
	write(1, &c, 1);
}

void	print_board(int **board, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col ++)
		{
			//printf("%d ", board[col][row]);
			
			ft_putnbr(board[col][row]);
			if (col != size - 1)
				write(1, " ", 1);
		}
		write (1, "\n", 1);
	}
}

int	col_is_full(int **board, int size, int column)
{
	for (int i = 0; i < size; i++)
	{
		if (board[column][i] == 0)
			return (0);
	}
	return (1);
}

int	row_is_full(int **board, int size, int row)
{
	for (int i = 0; i < size; i++)
	{
		if (board[i][row] == 0)
			return (0);
	}
	return (1);
}

int	check_from_top(int *viewpoints, int **board, int size, int col, int row)
{
	// Retrieve the top POV associated wiht the given posiion
	int	top_view = viewpoints[col];

	// Check the column from top view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the column to be completed
	if (board[col][0] == 0)
	{
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		if (board[col][i] != 0)
		{
			biggest = board[col][i]; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int current = board[col][i];
		if (current == 0) // If the box has not been initialized yet
			continue;
		if (current > biggest)	// If the box in the row is bigger than the previous bigger, it means we can see it. So viewables++;
		{
			biggest = current;
			viewables++;
		}
	}
	
	// If the collumn is complete, check if the viewables boxs correspond to needs
	if (col_is_full(board, size, col))
	{
		return (viewables == top_view);
	}
	// Else just check if the viewables boxes do not exceed the needs
	else 
	{
		return (viewables <= top_view);
	}
}

int	check_from_bottom(int *viewpoints, int **board, int size, int col, int row)
{
	// Retrieve the bottom POV associated wiht the given posiion
	int bott_view = viewpoints[size + col];

	// Check the column from bottom view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the column to be completed
	if (board[col][size - 1] == 0)
	{
		return (1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (board[col][i] != 0)
		{
			biggest = board[col][i]; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		int current = board[col][i];
		if (current == 0) // If the box has not been initialized yet
			continue;
		if (current > biggest)	// If the box in the row is bigger than the previous bigger, it means we can see it. So viewables++;
		{
			biggest = current;
			viewables++;
		}
	}
	
	// If the collumn is complete, check if the viewables boxs correspond to needs
	if (col_is_full(board, size, col))
	{
		return (viewables == bott_view);
	}
	// Else just check if the viewables boxes do not exceed the needs
	else 
	{
		return (viewables <= bott_view);
	}
}

int	check_from_left(int *viewpoints, int **board, int size, int col, int row)
{
	// Retrieve the left POV associated with the given position
	int left_view = viewpoints[size * 2 + row];

	// Check the column from left view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the row to be completed
	if (board[0][row] == 0)
	{
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		if (board[i][row] != 0)
		{
			biggest = board[i][row]; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int current = board[i][row];
		if (current == 0) // If the box has not been initialized yet
			continue;
		if (current > biggest)	// If the box in the row is bigger than the previous bigger, it means we can see it. So viewables++;
		{
			biggest = current;
			viewables++;
		}
	}

	// If the row is complete, check if the viewables boxs correspond to needs
	if (row_is_full(board, size, row))
	{
		return (viewables == left_view);
	}
	// Else just check if the viewables boxes do not exceed the needs
	else 
	{
		return (viewables <= left_view);
	}
}

int	check_from_right(int *viewpoints, int **board, int size, int col, int row)
{
	// Retrieve the right POV associated wiht the given posiion
	int right_view = viewpoints[size * 3 + row];

	// Check the column from right view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the row to be completed
	if (board[size-1][row] == 0)
	{
		return (1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (board[i][row] != 0)
		{
			biggest = board[i][row]; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		int current = board[i][row];
		if (current == 0) // If the box has not been initialized yet
			continue;
		if (current > biggest)	// If the box in the row is bigger than the previous bigger, it means we can see it. So viewables++;
		{
			biggest = current;
			viewables++;
		}
	}

	// If the row is complete, check if the viewables boxs correspond to needs
	if (row_is_full(board, size, row))
	{
		return (viewables == right_view);
	}
	// Else just check if the viewables boxes do not exceed the needs
	else 
	{
		return (viewables <= right_view);
	}
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

int	check_unique_boxes(int **board, int size, int col, int row)
{
	int *numbers = malloc(sizeof (int) * size);
	// Init array
	for (int i = 0; i < size; i++)
		numbers[i] = 0;
	// Check column (if not unique return 0)
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (board[col][i] == 0)	// If value not initialized, dont consider it
			continue;
		if (value_in_array(numbers, size, board[col][i]))
			return (0);
		else
			numbers[j++] = board[col][i];
	}
	// Reset array
	for (int i = 0; i < size; i++)
		numbers[i] = 0;
	j = 0;
	// Check row (if not unique return 0)
	for (int i = 0; i < size; i++)
	{
		if (board[i][row] == 0)	// If value not initialized, dont consider it
			continue;
		if (value_in_array(numbers, size, board[i][row]))
			return (0);
		else
			numbers[j++] = board[i][row];
	}
	// If nothing duplicated, return OK;
	free(numbers);
	return (1);
}

// Check if all sides view the correct amount of boxes
int	check_from_all_sides(int *viewpoints, int **board, int size, int col, int row)
{
	int	top_ok;
	int	bottom_ok;
	int	left_ok;
	int	right_ok;
	int	unique_boxes;

	top_ok = check_from_top(viewpoints, board, size, col, row);
	bottom_ok = check_from_bottom(viewpoints, board, size, col, row);
	left_ok = check_from_left(viewpoints, board, size, col, row);
	right_ok = check_from_right(viewpoints, board, size, col, row);
	unique_boxes = check_unique_boxes(board, size, col, row);

	// All four sides need to be safe to return 1
	return (top_ok && bottom_ok && left_ok && right_ok && unique_boxes);
}

void	set_basic_values(int *viewpoints, int **board, int size)
{
	// For each viewpoint in top section
	for (int i = 0; i < size; i++)
	{
		if (viewpoints[i] == 1) 
		{
			// If viewpoint only has one, set max value next to it
			board[i][0] = size;
		}
		else if (viewpoints[i] == size)
		{
			// If viewpoint needs to see all numbers, it's always in the order
			for (int j = 0; j < size; j++)
			{
				board[i][j] = j+1;
			}
		}
	}

	// For each viewpoint in bottom section
	for (int i = (size- 1); i < (size * 2); i++)
	{
		if (viewpoints[i] == 1) 
		{
			// If viewpoint only has one, set max value next to it
			board[i - size][size - 1] = size;
		}
		else if (viewpoints[i] == size)
		{
			// If viewpoint needs to see all numbers, it's always in the order
			int k = 1;
			for (int j = size - 1; j >= 0; j--)
			{
				board[i - size][j] = k++;
			}
		}
	}

	// For each viewpoint in left section
	for (int i = (size * 2 - 1); i < (size * 3); i++)
	{
		if (viewpoints[i] == 1) 
		{
			// If viewpoint only has one, set max value next to it
			board[0][i - (size * 2)] = size;
		}
		else if (viewpoints[i] == size)
		{
			// If viewpoint needs to see all numbers, it's always in the order
			for (int j = 0; j < size; j++)
			{
				board[0][j] = j+1;
			}
		}
	}

	// For each viewpoint in right section
	for (int i = (size * 3 - 1); i < (size * 3); i++)
	{
		if (viewpoints[i] == 1) 
		{
			// If viewpoint only has one, set max value next to it
			board[size - 1][i - (size * 3)] = size;
		}
		else if (viewpoints[i] == size)
		{
			// If viewpoint needs to see all numbers, it's always in the order
			int k = 1;
			for (int j = size - 1; j >= 0; j--)
			{
				board[i - size][j] = k++;
			}
		}
	}
}

int 	add_box(int* viewpoints, int **board, int size, int col, int row)
{
	int	is_already_assigned = 0;
	// If everything is complete, print & stop
	if (col == size && row == 0)
	{
		print_board(board, size);
		return 1;
	}

	if (board[col][row] != 0)
		is_already_assigned = 1;
	// Set the value and check if it's well placed, if not, check the next value
	for (int value = 1; value <= size; value++)
	{
		if (!is_already_assigned)
			board[col][row] = value;
		// If already assigned, dismiss all checks because second condition is not checked in OR
		if(is_already_assigned || check_from_all_sides(viewpoints, board, size, col, row))
		{
			// If we're on the last row, go to the next column at first row, repeat until last column
			if (row == size - 1)
			{
				if(add_box(viewpoints, board, size, col + 1, 0) == 1)
				{
					return (1);
				}
			}
			else
			{
				if (add_box(viewpoints, board, size, col, row + 1) == 1)
				{
					return (1);
				}
			}
		}
		else
			continue ;
	}

	// If iteration is not sucessfull, reset the position to 0 (for backtracking)
	board[col][row] = 0;
	return 0;
}

// Count the total count of numbers in the given string (separated by spaces)
int	count_nums(char *str)
{
	int	total;
	int	curr_is_num;

	total = 0;
	curr_is_num = 0;
	while (*str)
	{
		// If it is a number and we're not currently in a number, increment total and set currently number to true
		if (*str >= '0' && *str <= '9' && !curr_is_num)
		{
			total++;
			curr_is_num = 1;
		}
		// Else if current char is not a number
		else if (*str < '0' || *str > '9')
		{
			curr_is_num = 0;
		}
		str++;
	}
	return (total);
}

int	is_valid_split_num_input(char *str)
{
	// If starting char is not a number, invalid stirng
	if (*str < '0' || *str > '9')
		return (0);
	while (*str)
	{
		// If char is not a space and not a number, invalid string
		if (*str != ' ' && (*str < '0' || *str > '9'))
			return (0);
		// If more than one space separating number, invalid string
		if (*str == ' ' && (*(str + 1) < '0' || *(str + 1) > '9'))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_num_input(char *str)
{
	while (*str)
	{
		// If char is not a space and not a number, invalid string
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
    int size = 4;   // Size of the grid, default 4x4
	int **board;
	char *error_message;

	error_message = "Error\n";
	// If size argument
	if (argc == 3)
	{
		if (!is_valid_num_input(argv[2]))
		{
			ft_putstr(error_message);
			return (0);
		}
		size = ft_atoi(argv[2]);
	}

	// If invalid arguments number
    if (argc != 2 && argc != 3) 
    {
        ft_putstr(error_message);
        return (0);
    }

	// If numbers list is not valid
	if (!is_valid_split_num_input(argv[1]))
	{
		ft_putstr(error_message);
		return (0);
	}

    // Array of all possible viewpoints: top column / bottom column (from left to right) /// left row / right row (from top to bottom)
    int *viewpoints = malloc(sizeof(int) * size * 4);    

    // Fill the array with values given as arguments
    for (int i = 0; i < size * 4; i++)
    {
        viewpoints[i] = ft_atoi(argv[1]);
		// Remove added number from the list, so that next iteration will take the next number
		while (*(argv[1]) >= '0' && *(argv[1]) <= '9')
		{
			argv[1]++;
		}
		argv[1]++; // Skip the space at the end of the number (since there's only 1)
    }

	board = malloc(sizeof (int *) * size);	// Allocates the rows (arrays)
	for (int i = 0; i < size; i++)
	{
		// Allocates the columns (size of rows)
		// board[0] = first row; board[0][0] = first row first column
		board[i] = malloc(sizeof (int) * size);
	}

	// Initialize the board
	for (int col = 0; col < size; col++)
	{
		for (int row = 0; row < size; row++)
		{
			board[col][row] = 0;
		}
	}

	// If recursion isn't successfull, print Error, if it is successfull do nothing because result has already been printed
	
	set_basic_values(viewpoints, board, size);
	
	if(add_box(viewpoints, board, size, 0, 0) == 0)
	{
		ft_putstr(error_message);
	}
	
	// Test 4 : "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	// Test 5 : "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"
	// Test 6 : "3 2 2 3 2 1 5 1 2 2 4 3 3 2 1 2 2 4 1 2 3 3 2 2"
	// Test 7 : "4 1 5 5 3 4 2 1 2 2 2 2 3 5 2 5 3 4 3 2 1 2 1 3 2 2 3 6"
	// Test 8 : "4 3 4 1 5 4 3 2 2 4 2 4 1 3 5 4 3 3 5 2 3 1 3 2 2 1 2 3 2 4 3 3"
	// test 9 : "3 3 2 3 4 2 4 2 1 1 3 3 3 2 2 3 2 5 3 3 4 3 2 4 3 5 1 1 2 2 3 3 3 2 4 3"
}