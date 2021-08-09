// Check the column from top view
// We can always see the box in front of us
// If first one we see is not initialized,
// return and wait for the column to be completed
// The smallest box will always be the first one we see
// If the box has not been initialized yet
// If the box in the row is bigger than the previous bigger,
// it means we can see it. So viewables++;
// If the collumn is complete, check if the viewables boxs correspond to needs
// Else just check if the viewables boxes do not exceed the needs
int	check_from_top(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	int	viewables = 1;	
	int biggest;
	int top_view = viewpoints[col];
	
	if (board[col][0].height == 0)
	{
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		if (board[col][i].height != 0)
		{
			biggest = board[col][i].height;
			break ;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int current = board[col][i].height;
		if (current == 0)
			continue ;
		if (current > biggest)
		{
			biggest = current;
			viewables++;
		}
	}
	if (col_is_full(board, size, col))
	{
		return (viewables == top_view);
	}
	else
	{
		return (viewables <= top_view);
	}
}

// Retrieve the bottom POV associated wiht the given posiion
// Check the column from bottom view
// We can always see the box in front of us
// If first one we see is not initialized,
// return and wait for the column to be completed
// The smallest box will always be the first one we see
// If the box has not been initialized yet
// If the box in the row is bigger than the previous bigger,
// it means we can see it. So viewables++;
// If the collumn is complete, check if the viewables boxs correspond to needs
// Else just check if the viewables boxes do not exceed the needs
int	check_from_bottom(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	int bott_view = viewpoints[col];
	int	viewables = 1;	
	int biggest;

	if (board[col][size - 1].height == 0)
	{
		return (1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (board[col][i].height != 0)
		{
			biggest = board[col][i].height;
			break ;
		}
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		int current = board[col][i].height;
		if (current == 0)
			continue ;
		if (current > biggest)
		{
			biggest = current;
			viewables++;
		}
	}
	if (col_is_full(board, size, col))
	{
		return (viewables == bott_view);
	}
	else
	{
		return (viewables <= bott_view);
	}
}

// Retrieve the left POV associated with the given position
// Check the column from left view
// We can always see the box in front of us
// If first one we see is not initialized,
// return and wait for the row to be completed
// The smallest box will always be the first one we see
// If the box has not been initialized yet
// If the box in the row is bigger than the previous bigger,
// it means we can see it. So viewables++;
// If the row is complete, check if the viewables boxs correspond to needs
// Else just check if the viewables boxes do not exceed the needs
int	check_from_left(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	int left_view = viewpoints[row];
	int	viewables = 1;	
	int biggest;
	
	if (board[0][row].height == 0)
	{
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		if (board[i][row].height != 0)
		{
			biggest = board[i][row].height;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int current;
        current = board[i][row].height;
		if (current == 0)
			continue ;
		if (current > biggest)
		{
			biggest = current;
			viewables++;
		}
	}
	if (row_is_full(board, size, row))
	{
		return (viewables == left_view);
	}
	else
	{
		return (viewables <= left_view);
	}
}

// Retrieve the right POV associated wiht the given posiion
// Check the column from right view
// We can always see the box in front of us
// If first one we see is not initialized,
// return and wait for the row to be completed
// The smallest box will always be the first one we see
// If the box has not been initialized yet
// If the box in the row is bigger than the previous bigger,
// it means we can see it. So viewables++;
// If the row is complete, check if the viewables boxs correspond to needs
// Else just check if the viewables boxes do not exceed the needs
// Check if all sides view the correct amount of boxes
int	check_from_right(int *viewpoints, t_skyscraper **board, int size, int col, int row)
{
	int right_view = viewpoints[row];
	int	viewables = 1;	
	int biggest;
	if (board[size-1][row].height == 0)
	{
		return (1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (board[i][row].height != 0)
		{
			biggest = board[i][row].height; 
			break ;
		}
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		int current = board[i][row].height;
		if (current == 0)
			continue ;
		if (current > biggest)
		{
			biggest = current;
			viewables++;
		}
	}
	if (row_is_full(board, size, row))
	{
		return (viewables == right_view);
	}
	else
	{
		return (viewables <= right_view);
	}
}

// All four sides need to be safe to return 1
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
	return (top_ok && bottom_ok && left_ok && right_ok && unique_boxes);
}