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
/*void	edge_clues(t_viewpoints viewpoints, t_skyscraper **board, int size)
{
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.top[i];
		t_skyscraper skyscraper = board[i][0];
		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[i][j].height = j + 1;
				board[i][j].fixed = 1;
			}
		}
		else if (pov == 1)
		{
			board[i][0].height = size;
			board[i][0].fixed = 1;
		}
		else
		{
			for (int j = 0; j < pov - 1; j++)	
			{
				remove_possibilities(board[i][j], (size - pov + 2 + j), size);
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.bottom[i];
		t_skyscraper skyscraper = board[i][size - 1];

		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[i][size - 1 - j].height = j + 1;
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
	for (int i = 0; i < size; i++)
	{
		int pov = viewpoints.right[i];
		t_skyscraper skyscraper = board[size - 1][i];

		if (pov == size)
		{
			for (int j = 0; j < size; j++)
			{
				board[size - 1 - j][i].height = j + 1;
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
}*/

void	edge_clues(t_viewpoints viewpoints, t_skyscraper **board, int size)
{
	int	i;
	int	pov;
	int	j;

	i = 0;
	pov = 0;
	j = 0;
	while (i < size)
	{
		pov = viewpoints.top[i];
		skyscraper = board[i][0];
		if (pov == size)
		{
			while (j < size)
			{
				board[i][j].height = j + 1;
				board[i][j].fixed = 1;
				j++;
			}
		}
		else if (pov == 1)
		{
			board[i][0].height = size;
			board[i][0].fixed = 1;
		}
		else
		{
			while (j < pov - 1)
			{
				remove_possibilities(board[i][j], (size - pov + 2 + j), size);
				j++;
			}
		}
		i++;
	}
	while (i < size)
	{
		pov = viewpoints.bottom[i];
		skyscraper = board[i][size - 1];
		if (pov == size)
		{
			while (j < size)
			{
				board[i][size - 1 - j].height = j + 1;
				board[i][size - 1 - j].fixed = 1;
				j++;
			}
		}
		else if (pov == 1)
		{
			board[i][size - 1].height = size;
			board[i][size - 1].fixed = 1;
		}
		else
		{
			while (j < pov - 1)
			{
				remove_possibilities(board[i][size - 1 - j], (size - pov + 2 + j), size);
				j++;
			}
		}
		i++;
	}
	while (i < size)
	{
		pov = viewpoints.left[i];
		skyscraper = board[0][i];
		if (pov == size)
		{
			while (j < size)
			{
				board[j][i].height = j + 1;
				board[j][i].fixed = 1;
				j++;
			}
		}
		else if (pov == 1)
		{
			board[0][i].height = size;
			board[0][i].fixed = 1;
		}
		else
		{
			while (j < pov - 1)
			{
				remove_possibilities(board[j][i], (size - pov + 2 + j), size);
				j++;
			}
		}
		i++;
	}
	while (i < size)
	{
		pov = viewpoints.right[i];
		skyscraper = board[size - 1][i];
		if (pov == size)
		{
			while (j < size)
			{
				board[size - 1 - j][i].height = j + 1;
				board[size - 1 - j][i].fixed = 1;
				j++;
			}
		}
		else if (pov == 1)
		{
			board[size - 1][i].height = size;
			board[size - 1][i].fixed = 1;
		}
		else
		{
			while (j < pov - 1)
			{
				remove_possibilities(board[size - 1 - j][i], (size - pov + 2 + j), size);
				j++;
			}
		}
		i++;
	}
}
