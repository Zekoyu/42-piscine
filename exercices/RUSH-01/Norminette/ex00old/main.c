// For each row / column (since we have all clues given, all columns 
//rows will always be modified), check if only 1 skyscraper has a given height,
// if it's the only one, set that height as definitive
// Size of the grid, default 4x4
// If size argument
// If invalid arguments number
// If numbers list is not valid
// Array of all possible viewpoints: top column / 
//bottom column (from left to right) ///
// left row / right row (from top to bottom)
// Convert input string to int array
// Remove added number from the list, so that next 
//iteration will take the next number
// Skip the space at the end of the number (since there's only 1)
//Viewpoints : [0] = top; [1] = bottom; [2] = left; [3] = right
// Alloc memory for 4 POVs lines
// Top line POVs
// Bottom line POVs
// Left line POVs
// Right line POVs
// Free viewpoints values (not used anymore)
// Allocates the rows (arrays)
// Allocates the columns (size of rows)
// board[0] = first col; board[0][0] = first col first row
// Initialize the board
// Start eliminating possible values using the given clues for each side
// Then, we kinda bruteforce,
// trying all possible solutions (never with 2 skyscrapers of the same size),
// and filter them to get only the one matching the clues on the edges
//solve_sequences(board, size);
//printf("1st step: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
//if(test_backtrack(viewpoints, board, size, 0, 0) == 0)
//	ft_putstr("No solutions");
// 4: "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2
// 5: "4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"
// 7: "4 1 5 5 3 4 2 1 2 2 2 2 3 5 2 5 3 4 3 2 1 2 1 3 2 2 3 6"
// 8 : "4 3 4 1 5 4 3 2 2 4 2 4 1 3 5 4 3 3 5 2 3 1 3 2 2 1 2 3 2 4 3 3"
// 9: "3 3 2 3 4 2 4 2 1 1 3 3 3 2 2 3 2 5 3 3 
// 4 3 2 4 3 5 1 1 2 2 3 3 3 2 4 3"

int main(int argc, char *argv[])
{
    int size = 4;   
	t_skyscraper **board;
	char *error_message;

	error_message = "Error\n";
	if (argc == 3)
	{
		if (!is_valid_num_input(argv[2]))
		{
			ft_putstr(error_message);
			return (0);
		}
		size = ft_atoi(argv[2]);
	}
    if (argc != 2 && argc != 3) 
    {
        ft_putstr(error_message);
        return (0);
    }
	if (!is_valid_split_num_input(argv[1]))
	{
		ft_putstr(error_message);
		return (0);
	}
    t_viewpoints viewpoints;
	int *viewpoints_values;

	viewpoints_values = malloc(sizeof (int) * size * 4);
	for (int i = 0; i < size * 4; i++)
    {
        viewpoints_values[i] = ft_atoi(argv[1]);
		while (*(argv[1]) >= '0' && *(argv[1]) <= '9')
		{
			argv[1]++;
		}
		argv[1]++;
    }
	for (int i = 0; i < 4; i++)
	{
		viewpoints.top = malloc(sizeof (int) * size);
		viewpoints.bottom = malloc(sizeof (int) * size);
		viewpoints.left = malloc(sizeof (int) * size);
		viewpoints.right = malloc(sizeof (int) * size);
	}
	for (int i = 0; i < size; i++)
	{
		viewpoints.top[i] = viewpoints_values[i];
	}
	for (int i = size, j = 0; i < (size * 2); i++, j++)
	{
		viewpoints.bottom[j] = viewpoints_values[i];
	}
	for (int i = (size * 2), j = 0; i < (size * 3); i++, j++)
	{
		viewpoints.left[j] = viewpoints_values[i];
	}
	for (int i = (size * 3), j = 0; i < (size * 4); i++, j++)
	{
		viewpoints.right[j] = viewpoints_values[i];
	}
	free(viewpoints_values);
	board = malloc(sizeof (int *) * size);
	for (int i = 0; i < size; i++)
	{
		board[i] = malloc(sizeof (t_skyscraper) * size);
	}
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
	edge_clues(viewpoints, board, size);
	constraint_propagation(board, size);
	constraint_propagation(board, size);
	elimination(board, size);
	print_possibilities(board, size);
	end = clock();
	printf("2nd step: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
