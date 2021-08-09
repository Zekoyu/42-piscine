#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "board_structures.h"


void	backtracking_2(t_board *board_infos, int col, int row, int *res);
int	backtracking_3(int *possible_values, t_skyscraper *skyscraper, int *res);
int backtracking(t_board *board_infos, int col, int row);


void	ft_putstr(char *str)
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

int	print_board(t_skyscraper **board, int size)
{	
	int	row;
	int	col;

	row = -1;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{			
			ft_putnbr(board[col][row].height);
			if (col != size - 1)
				write(1, " ", 1);
		}
		write (1, "\n", 1);
	}
	return (1);
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

/////////// RM
void	edge_clues(t_viewpoints viewpoints, t_skyscraper **board, int size)
{
	// For each top viewpoint
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.top[i];
		t_skyscraper skyscraper = board[i][0];

		// If pov = n; we know the whole column should be increasing from 1 to N
		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[i][j].height = j + 1;
				board[i][j].fixed = 1;
			}
		}
		// If pov = 1, the skyscraper right in front should N tall;
		else if (pov == 1)
		{
			board[i][0].height = size;
			board[i][0].fixed = 1;
		}
		else	// For all values between 1 and N, apply the formula (N - c + 2 + d)
		{
			for (int j = 0; j < pov - 1; j++)	// We can exclude heights for skyscrapers up to clue value - 1
			{
				remove_possibilities(board[i][j], (size - pov + 2 + j), size);
			}
		}
	}

	// Same for bottom viewpoints
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.bottom[i];
		t_skyscraper skyscraper = board[i][size - 1];

		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[i][size - 1 - j].height = j + 1;	// Starts from the bottom of the column
				board[i][size - 1 - j].fixed = 1;
			}
		}
		else if (pov == 1)
		{
			board[i][size - 1].height = size;
			board[i][size - 1].fixed = 1;
		}
		else
		{
			for (int j = 0; j < pov - 1; j++)
				remove_possibilities(board[i][size - 1 - j], (size - pov + 2 + j), size);
		}
	}

	// Same for left viewpoints
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.left[i];
		t_skyscraper skyscraper = board[0][i];

		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[j][i].height = j + 1;
				board[j][i].fixed = 1;
			}
		}
		else if (pov == 1)
		{
			board[0][i].height = size;
			board[0][i].fixed = 1;
		}
		else
		{
			for (int j = 0; j < pov - 1; j++)
				remove_possibilities(board[j][i], (size - pov + 2 + j), size);
		}
	}

	// Same for right viewpoints
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.right[i];
		t_skyscraper skyscraper = board[size - 1][i];

		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[size - 1 - j][i].height = j + 1;	// Starts from the right of the row
				board[size - 1 - j][i].fixed = 1;
			}
		}
		else if (pov == 1)
		{
			board[size - 1][i].height = size;
			board[size - 1][i].fixed = 1;
		}
		else
		{
			for (int j = 0; j < pov - 1; j++)
				remove_possibilities(board[size - 1 - j][i], (size - pov + 2 + j), size);
		}
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
	int	col;
	int	row;
	int	value;
	int	i;

	col = 0;
	row = 0;
	while (col < size)
	{
		row = 0;
		while (row < size)
		{
			value = board[col][row].height;
			if (value != 0)
			{
				i = 0;
				while (i < size)
				{
					board[col][i].possibilities[value - 1] = 0;
					i++;
				}
				i = 0;
				while (i < size)
				{
					board[i][row].possibilities[value - 1] = 0;
					i++;
				}
			}
			row++;
		}
		col++;
	}
}

//////// RM
void elimination(t_skyscraper **board, int size)
{	
	int *single_possibilities = malloc(sizeof(int) * size);	// Stores single possibilities, if a value is duplicate, set it to 0, then 

	// Check each column first
	// For each skyscraper in the column, check if the other ones have the same possibilities, if another one have, go to next value
	for (int col = 0; col < size; col++)
	{
		// init single possibiliites
		for (int i = 0; i < size; i++)
		{
			single_possibilities[i] = -1;
		}

		for (int row = 0; row < size; row++)
		{
			t_skyscraper skyscraper = board[col][row];
			if (skyscraper.height == 0)	// If skyscraper has no certain value yet
			{
				// Iterate through possible values of the skyscraper
				for (int i = 0; i < size; i++)
				{
					if (skyscraper.possibilities[i] == 0 || single_possibilities[i] == 0)	// If no possibility for this num OR possibility not single, continue
						continue;
					if(skyscraper.possibilities[i] != single_possibilities[i])
					{
						single_possibilities[i] = skyscraper.possibilities[i];
					}
					else
					{
						single_possibilities[i] = 0;
					}
				}
			}
		}

		// Once the column is completed, set the value of unique possibilities
		for (int i = 0; i < size; i++)
		{
			if (single_possibilities[i] >= 1)
			{
				for (int j = 0; j < size; j++)
				{
					t_skyscraper *skyscraper = &(board[col][j]);
					if (skyscraper -> height != 0) 	// Do not change the height of a fixed skyscraper
						continue;
					if (skyscraper -> possibilities[i] == i + 1)	// If it's the one which has unique possibility
					{
						skyscraper -> height = i + 1;	// Set fixed height to this one
						skyscraper -> fixed = 1;
						constraint_propagation(board, size); // Propagate the just added constrain
						break; // Exit the loop since only one can be unique
					}
				}
			}
		}
	}


	// Check each row
	for (int row = 0; row < size; row++)
	{
		for (int i = 0; i < size; i++)
			single_possibilities[i] = -1;

		for (int col = 0; col < size; col++)
		{
			t_skyscraper skyscraper = board[col][row];
			if (skyscraper.height == 0)
			{
				for (int i = 0; i < size; i++)
				{
					if (skyscraper.possibilities[i] == 0 || single_possibilities[i] == 0)
						continue;
					if(skyscraper.possibilities[i] != single_possibilities[i])
						single_possibilities[i] = skyscraper.possibilities[i];
					else
						single_possibilities[i] = 0;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			if (single_possibilities[i] >= 1)
			{
				for (int j = 0; j < size; j++)
				{
					t_skyscraper *skyscraper = &(board[j][row]);
					if (skyscraper -> height != 0) 	// Do not change the height of a fixed skyscraper
						continue;
					if (skyscraper -> possibilities[i] == i + 1)
					{
						skyscraper -> height = i + 1;
						skyscraper -> fixed = 1;
						constraint_propagation(board, size);
						break;
					}
				}
			}
		}
	}
}

// Get possible skyscraper values exluding 0s
int	*get_possible_values(t_skyscraper skyscraper, int size)
{
	int	count;
	int	*result;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (++i < size)
		if (skyscraper.possibilities[i] != 0)
			count++;
	result = malloc(sizeof (int) * count + 1);
	j = -1;
	i = 0;
	while (j < count)
	{
		if (skyscraper.possibilities[i] != 0)
		{
			result[j] = skyscraper.possibilities[i];
			j++;
		}
		i++;
	}
	result[count] = -1;
	return (result);
}

// Check if value in array
int	value_in_array(int *values_arr, int values_arr_size, int value)
{
	int	i;

	i = 0;
	while (i < values_arr_size)
	{
		if (values_arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}



// Check for unique boxes in column
int check_unique_boxes_col(t_skyscraper **board, int size, int col, int *numbers)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
		numbers[i] = 0;
	j = 0;
	i = -1;
	while (++i < size)
	{
		if (board[col][i].height == 0)
			continue ;
		if (value_in_array(numbers, size, board[col][i].height))
			return (0);
		else
			numbers[j++] = board[col][i].height;
	}
	return (1);
}

// Check for unique boxes in row
int check_unique_boxes_row(t_skyscraper **board, int size, int row, int *numbers)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
		numbers[i] = 0;
	j = 0;
	i = 0;
	while (++i < size)
	{
		if (board[i][row].height == 0)
			continue ;
		if (value_in_array(numbers, size, board[i][row].height))
			return (0);
		else
			numbers[j++] = board[i][row].height;
	}
	return (1);
}

// Init array (containing already seen values)
// Check column (if not unique return 0)
// If value not initialized, dont consider it
// Reset array
// Check row (if not unique return 0)
// If value not initialized, dont consider it
// If nothing duplicated, return OK;
int	check_unique_boxes(t_skyscraper **board, int size, int col, int row)
{
	int	*numbers;
	int	i;
	int	j;

	numbers = malloc(sizeof (int) * size);
	if (!check_unique_boxes_col(board, size, col, numbers))
		return (0);
	if (!check_unique_boxes_row(board, size, row, numbers))
		return (0);
	free(numbers);
	return (1);
}

// Check if column is fully filled
int	col_is_full(t_skyscraper **board, int size, int column)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (board[column][i].height == 0)
			return (0);
		i++;
	}
	return (1);
}

// Check if column is fully filled
int	row_is_full(t_skyscraper **board, int size, int row)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (board[i][row].height == 0)
			return (0);
		i++;
	}
	return (1);
}

// Check the column from top view
// We can always see the box in front of us
// If first one we see is not initialized, return and wait 
// for the column to be completed
// The smallest box will always be the first one we see
// If the box has not been initialized yet
// If the box in the row is bigger than the previous bigger, 
// it means we can see it. So viewables++;
// If the collumn is complete, check if the viewables boxs correspond to needs
// Else just check if the viewables boxes do not exceed the needs
int	check_from_top(t_board *board_infos, int col)
{
	int				viewables;
	int				biggest;
	int				i;
	t_skyscraper	**board;

	viewables = 1;
	biggest = 0;
	board = board_infos -> board;
	if (board[col][0].height == 0)
		return (1);
	i = -1;
	while (++i < board_infos -> size)
	{
		if (board[col][i].height != 0 && board[col][i].height > biggest)
		{
			if (biggest != 0)
				viewables++;
			biggest = board[col][i].height;
		}
	}
	if (col_is_full(board, board_infos->size, col))
		return (viewables == board_infos->viewpoints.top[col]);
	else
		return (viewables <= board_infos->viewpoints.top[col]);
}

int	check_from_bottom(t_board *board_infos, int col)
{
	int				viewables;
	int				biggest;
	int				i;
	t_skyscraper	**board;

	viewables = 1;
	biggest = 0;
	board = board_infos -> board;
	if (board[col][board_infos->size - 1].height == 0)
		return (1);
	i = board_infos->size;
	while (--i >= 0)
	{
		if (board[col][i].height != 0 && board[col][i].height > biggest)
		{
			if (biggest != 0)
				viewables++;
			biggest = board[col][i].height;
		}
	}
	if (col_is_full(board, board_infos->size, col))
		return (viewables == board_infos->viewpoints.bottom[col]);
	else
		return (viewables <= board_infos->viewpoints.bottom[col]);
}

int	check_from_left(t_board *board_infos, int row)
{
	int				viewables;
	int				biggest;
	int				i;
	t_skyscraper	**board;

	viewables = 1;
	biggest = 0;
	board = board_infos -> board;
	if (board[0][row].height == 0)
		return (1);
	i = -1;
	while (++i < board_infos -> size)
	{
		if (board[i][row].height != 0 && board[i][row].height > biggest)
		{
			if (biggest != 0)
				viewables++;
			biggest = board[i][row].height;
		}
	}
	if (row_is_full(board, board_infos->size, row))
		return (viewables == board_infos->viewpoints.left[row]);
	else
		return (viewables <= board_infos->viewpoints.left[row]);
}

int	check_from_right(t_board *board_infos, int row)
{
	int				viewables;
	int				biggest;
	int				i;
	t_skyscraper	**board;

	viewables = 1;
	biggest = 0;
	board = board_infos -> board;
	if (board[board_infos->size - 1][row].height == 0)
		return (1);
	i = board_infos->size;
	while (--i >= 0)
	{
		if (board[i][row].height != 0 && board[i][row].height > biggest)
		{
			if (biggest != 0)
				viewables++;
			biggest = board[i][row].height;
		}
	}
	if (row_is_full(board, board_infos->size, row))
		return (viewables == board_infos->viewpoints.right[row]);
	else
		return (viewables <= board_infos->viewpoints.right[row]);
}

// Check if all sides view the correct amount of boxes
// All four sides need to be safe to return 1
int	check_from_all_sides(t_board *board_infos, int col, int row)
{
	int	top_ok;
	int	bottom_ok;
	int	left_ok;
	int	right_ok;
	int	unique_boxes;

	top_ok = check_from_top(board_infos, col);
	bottom_ok = check_from_bottom(board_infos, col);
	left_ok = check_from_left(board_infos, row);
	right_ok = check_from_right(board_infos, row);
	unique_boxes = check_unique_boxes(board_infos->board, 
			board_infos->size, col, row);	
	return (top_ok && bottom_ok && left_ok && right_ok && unique_boxes);
}


void	backtracking_2(t_board *board_infos, int col, int row, int *res)
{
	int	i;

	if (*res == 1)
		return ;
	if (row == board_infos->size - 1)
	{
		if (backtracking(board_infos, col + 1, 0) == 1)
			*res = 1;
	}
	else
	{
		if (backtracking(board_infos, col, row + 1) == 1)
			*res = 1;
	}	
}

int	backtracking_3(int *possible_values, t_skyscraper *skyscraper, int *res)
{
	if (*res == 1)
		return (1);
	free (possible_values);
	if (!(skyscraper -> fixed))
		skyscraper -> height = 0;
	return *res;
}

// Backtracking ("Bruteforce") algorithm
// If fixed height skyscraper, directly go to next one
// If everything is complete, print & stop
// Print board returns 1 to gain lines
// Backtracking_3 returns the result to gain 1 line
int 	backtracking(t_board *board_infos, int col, int row)
{
	t_skyscraper	*skyscraper;
	int				*possible_values;
	int				i;
	int				result;
	int				size;

	size = board_infos->size;
	result = 0;
	if (col == size && row == 0)
	{
		(print_board(board_infos->board, size));
		return (1);
	}
	skyscraper = &(board_infos->board[col][row]);
	possible_values = get_possible_values(*skyscraper, size);
	if (skyscraper -> height > 0)
		backtracking_2(board_infos, col, row, &result);
	else
	{
		i = -1;
		while (possible_values[++i] > 0)
		{
			skyscraper -> height = possible_values[i];
			if (check_from_all_sides(board_infos, col, row))
				backtracking_2(board_infos, col, row, &result);
		}
	}
	return (backtracking_3(possible_values, skyscraper, &result));
}


// If size argument
// If invalid arguments number
// If numbers list is not valid
int	check_args_validity(int argc, char *argv[], int *size, char *error_msg)
{
	*size = 4;
	if (argc == 3)
	{
		if (!is_valid_num_input(argv[2]))
		{
			ft_putstr(error_msg);
			return (0);
		}
		*size = ft_atoi(argv[2]);
	}
	if (argc != 2 && argc != 3)
	{
		ft_putstr(error_msg);
		return (0);
	}	
	if (!is_valid_split_num_input(argv[1]))
	{
		ft_putstr(error_msg);
		return (0);
	}
	return (1);
}

// Remove added number from the list, so that next iteration will 
// take the next number
//
// Skip the space at the end of the number (since there's only 1)
int	*init_viewpoints(char *argv[], int size)
{
	int	*values;
	int	i;

	i = -1;
	values = malloc(sizeof (int) * size * 4);
	while (++i < size * 4)
	{
		values[i] = ft_atoi(argv[1]);
		while (*(argv[1]) >= '0' && *(argv[1]) <= '9')
		{
			argv[1]++;
		}
		argv[1]++;
	}
	return (values);
}

// Size of the grid, default 4x4
// Array of all possible viewpoints: top column 
// bottom column (from left to right) left row / right row (from top to bottom)
//
// Convert input string to int array
// Viewpoints : [0] = top; [1] = bottom; [2] = left; [3] = right
//
// Alloc memory for 4 POVs lines
//
// 4: "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2
// 5: "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"
// 7: "4 1 5 5 3 4 2 1 2 2 2 2 3 5 2 5 3 4 3 2 1 2 1 3 2 2 3 6"
// 8 : "4 3 4 1 5 4 3 2 2 4 2 4 1 3 5 4 3 3 5 2 3 1 3 2 2 1 2 3 2 4 3 3"
// 9: "3 3 2 3 4 2 4 2 1 1 3 3 3 2 2 3 2 5 3 3 4 3 2 4 3 5 1 1 2 2 3 3 3 2 4 3"
int main(int argc, char *argv[])
{
	int				size;
	t_skyscraper	**board;
	t_viewpoints	viewpoints;
	int 			*viewpoints_values;
	int				i;

	if (!check_args_validity(argc, argv, &size, "Error\n"))
		return (0);
	viewpoints_values = init_viewpoints(argv, size);
	i = -1;
	while (++i < 4)
	{
		viewpoints.top = malloc(sizeof (int) * size);
		viewpoints.bottom = malloc(sizeof (int) * size);
		viewpoints.left = malloc(sizeof (int) * size);
		viewpoints.right = malloc(sizeof (int) * size);
	}
	for (int i = 0; i < size; i++)
		viewpoints.top[i] = viewpoints_values[i];

	for (int i = size, j = 0; i < (size * 2); i++, j++)
		viewpoints.bottom[j] = viewpoints_values[i];

	for (int i = (size * 2), j = 0; i < (size * 3); i++, j++)
		viewpoints.left[j] = viewpoints_values[i];

	for (int i = (size * 3), j = 0; i < (size * 4); i++, j++)
		viewpoints.right[j] = viewpoints_values[i];

	free(viewpoints_values);

	board = malloc(sizeof (int *) * size);	// Allocates the rows (arrays)
	for (int i = 0; i < size; i++)
	{
		// Allocates the columns (size of rows)
		// board[0] = first col; board[0][0] = first col first row
		board[i] = malloc(sizeof (t_skyscraper) * size);
	}

	// Initialize the board
	for (int col = 0; col < size; col++)
	{
		for (int row = 0; row < size; row++)
		{
			board[col][row].height = 0;
			board[col][row].fixed = 0;

			board[col][row].possibilities = malloc (sizeof (int) * size);
			for (int i = 0; i < size; i++)
			{
				board[col][row].possibilities[i] = i + 1;
			}
		}
	}

	// Start eliminating possible values using the given clues for each side
	edge_clues(viewpoints, board, size);
	// Then, if some skyscrapers are already placed with fixed height, remove it's
	// height from the possibilities of all skyscrapers of the same row and column
	constraint_propagation(board, size);
	// For each row / column (since we have all clues given, all columns / rows will
	// always be modified), check if only 1 skyscraper has a given height, if it's the only
	// one, set that height as definitive
	elimination(board, size);
	t_board board_infos = {viewpoints, board, size};
	if(backtracking(&board_infos, 0, 0) == 0)
		ft_putstr("Error\n");
}