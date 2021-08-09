#include <stdlib.h>
#include <unistd.h>

typedef struct s_skyscraper t_skyscraper;
struct s_skyscraper
{
	int	height;
	int *possibilities;
	int fixed;
};

typedef struct s_clues_list t_clues_list;
struct s_clues_list
{
	int *top;
	int *bottom;
	int *left;
	int *right;
};

typedef struct s_viewpoints t_viewpoints;
struct s_viewpoints
{
	int *top;
	int *bottom;
	int *left;
	int *right;
};

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

void	print_board(t_skyscraper **board, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col ++)
		{			
			ft_putnbr(board[col][row].height);
			if (col != size - 1)
				write(1, " ", 1);
		}
		write (1, "\n", 1);
	}
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















void	print_possibilities(t_skyscraper **board, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col ++)
		{
			// If unsure value, print possibilities
			if (board[col][row].height == 0)
			{
				printf("%s", "[");
				for (int j = 0; j < size; j++)
				{
					if (j != size-1)
						printf("%d, ", board[col][row].possibilities[j]);
					else
						printf("%d", board[col][row].possibilities[j]);
				}
				printf("%s", "] ");
			}
			// If known value, print value directly
			else
			{
				printf("%s", "{");
				for (int i = 0; i < size; i++)
				{
					if (i == size/2)
					{
						printf("%d", board[col][row].height);
					}
					else 
					{
						printf("%s", "   ");
					}
				}
				printf("%s", " }");
			}
		}
		printf("%s", "\n");
	}
}

void	remove_possibilities(t_skyscraper skyscraper, int rm_start, int rm_end)
{
	// Remove the given number from possibilities; ex: want to remove between 3 and 5, so remove list[2], list[3], list[4]
	for (int i = rm_start; i <= rm_end; i++)
	{
		skyscraper.possibilities[i - 1] = 0;
	}
}

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


void	constraint_propagation(t_skyscraper **board, int size)
{
	for (int col = 0; col < size; col++)
	{
		for (int row = 0; row < size; row++)
		{
			// If skyscraper already has a fixed height
			int value = board[col][row].height;
			if (value != 0)
			{
				// Set each nearby cell as constrained

				// For each skyscraper in the same col
				for (int i = 0; i < size; i++)
				{
					board[col][i].possibilities[value - 1] = 0;	// Remove this possible value
				}
				// For each skyscraper in the same row
				for (int i = 0; i < size; i++)
				{
					board[i][row].possibilities[value - 1] = 0;	// Remove this possible value
				}
			}
		}
	}
}


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
						break;
					}
				}
			}
		}
	}
}

void solve_sequences(t_skyscraper **board, int size)
{
	// Test columns
	for (int col = 0; col < size; col++)
	{

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

int	check_unique_boxes(t_skyscraper **board, int size, int col, int row)
{
	int *numbers = malloc(sizeof (int) * size);
	// Init array
	for (int i = 0; i < size; i++)
		numbers[i] = 0;
	// Check column (if not unique return 0)
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (board[col][i].height == 0)	// If value not initialized, dont consider it
			continue;
		if (value_in_array(numbers, size, board[col][i].height))
			return (0);
		else
			numbers[j++] = board[col][i].height;
	}
	// Reset array
	for (int i = 0; i < size; i++)
		numbers[i] = 0;
	j = 0;
	// Check row (if not unique return 0)
	for (int i = 0; i < size; i++)
	{
		if (board[i][row].height == 0)	// If value not initialized, dont consider it
			continue;
		if (value_in_array(numbers, size, board[i][row].height))
			return (0);
		else
			numbers[j++] = board[i][row].height;
	}
	// If nothing duplicated, return OK;
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

int	check_from_top(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	// Check the column from top view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;

	int top_view = viewpoints[col];
	// If first one we see is not initialized, return and wait for the column to be completed
	if (board[col][0].height == 0)
	{
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		if (board[col][i].height != 0)
		{
			biggest = board[col][i].height; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int current = board[col][i].height;
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

int	check_from_bottom(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	// Retrieve the bottom POV associated wiht the given posiion
	int bott_view = viewpoints[col];

	// Check the column from bottom view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the column to be completed
	if (board[col][size - 1].height == 0)
	{
		return (1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (board[col][i].height != 0)
		{
			biggest = board[col][i].height; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		int current = board[col][i].height;
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

int	check_from_left(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	// Retrieve the left POV associated with the given position
	int left_view = viewpoints[row];

	// Check the column from left view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the row to be completed
	if (board[0][row].height == 0)
	{
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		if (board[i][row].height != 0)
		{
			biggest = board[i][row].height; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int current = board[i][row].height;
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

int	check_from_right(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	// Retrieve the right POV associated wiht the given posiion
	int right_view = viewpoints[row];

	// Check the column from right view
	int	viewables = 1;	// We can always see the box in front of us
	int biggest;
	// If first one we see is not initialized, return and wait for the row to be completed
	if (board[size-1][row].height == 0)
	{
		return (1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (board[i][row].height != 0)
		{
			biggest = board[i][row].height; // The smallest box will always be the first one we see
			break;
		}
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		int current = board[i][row].height;
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

// Check if all sides view the correct amount of boxes
int	check_from_all_sides(t_viewpoints viewpoints, t_skyscraper **board, int size, int col, int row)
{
	int	top_ok;
	int	bottom_ok;
	int	left_ok;
	int	right_ok;
	int	unique_boxes;

	top_ok = check_from_top(viewpoints.top, board, size, col, row);
	bottom_ok = check_from_bottom(viewpoints.bottom, board, size, col, row);
	left_ok = check_from_left(viewpoints.left, board, size, col, row);
	right_ok = check_from_right(viewpoints.right, board, size, col, row);
	unique_boxes = check_unique_boxes(board, size, col, row);

	// All four sides need to be safe to return 1
	return (top_ok && bottom_ok && left_ok && right_ok && unique_boxes);
}

int 	test_backtrack(t_viewpoints viewpoints, t_skyscraper **board, int size, int col, int row)
{
	// If everything is complete, print & stop
	if (col == size && row == 0)
	{
		print_possibilities(board, size);
		return 1;
	}

	t_skyscraper *skyscraper = &(board[col][row]);
	int *possible_values = get_possible_values(*skyscraper, size);

	if (skyscraper -> height > 0)
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
	else
	{
		for (int i = 0; possible_values[i] != -1; i++)
		{
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
	return 0;
}

int main(int argc, char *argv[])
{
    int size = 4;   // Size of the grid, default 4x4
	t_skyscraper **board;
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
    t_viewpoints viewpoints;
	int *viewpoints_values;

	viewpoints_values = malloc(sizeof (int) * size * 4);

	// Convert input string to int array
	for (int i = 0; i < size * 4; i++)
    {
        viewpoints_values[i] = ft_atoi(argv[1]);
		// Remove added number from the list, so that next iteration will take the next number
		while (*(argv[1]) >= '0' && *(argv[1]) <= '9')
		{
			argv[1]++;
		}
		argv[1]++; // Skip the space at the end of the number (since there's only 1)
    }


	//Viewpoints : [0] = top; [1] = bottom; [2] = left; [3] = right

	// Alloc memory for 4 POVs lines
	for (int i = 0; i < 4; i++)
	{
		viewpoints.top = malloc(sizeof (int) * size);
		viewpoints.bottom = malloc(sizeof (int) * size);
		viewpoints.left = malloc(sizeof (int) * size);
		viewpoints.right = malloc(sizeof (int) * size);
	}

    // Top line POVs
	for (int i = 0; i < size; i++)
	{
		viewpoints.top[i] = viewpoints_values[i];
	}

	// Bottom line POVs
	for (int i = size, j = 0; i < (size * 2); i++, j++)
	{
		viewpoints.bottom[j] = viewpoints_values[i];
	}

	// Left line POVs
	for (int i = (size * 2), j = 0; i < (size * 3); i++, j++)
	{
		viewpoints.left[j] = viewpoints_values[i];
	}

	// Right line POVs
	for (int i = (size * 3), j = 0; i < (size * 4); i++, j++)
	{
		viewpoints.right[j] = viewpoints_values[i];
	}

	// Free viewpoints values (not used anymore)
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

	// Then, if some skyscrapers are already placed with fixed height, remove it's height from the possibilities of all skyscrapers of the same row and column
	constraint_propagation(board, size);

	// For each row / column (since we have all clues given, all columns / rows will always be modified), check if only 1 skyscraper has a given height, if it's the only one, set that height as definitive
	elimination(board, size);

	// Then, we kinda bruteforce, trying all possible solutions (never with 2 skyscrapers of the same size), and filter them to get only the one matching the clues on the edges
	//solve_sequences(board, size);

	if(test_backtrack(viewpoints, board, size, 0, 0) == 0)
	{
		ft_putstr("No solutions");
	}

	//print_possibilities(board, size);

	// 4: "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2
	// 5: "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"
	// 7: "4 1 5 5 3 4 2 1 2 2 2 2 3 5 2 5 3 4 3 2 1 2 1 3 2 2 3 6"
	// 9: "3 3 2 3 4 2 4 2 1 1 3 3 3 2 2 3 2 5 3 3 4 3 2 4 3 5 1 1 2 2 3 3 3 2 4 3"
}
