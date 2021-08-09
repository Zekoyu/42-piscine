// Stores single possibilities, if a value is duplicate, set it to 0, then 
// Check each column first
// For each skyscraper in the column,
// check if the other ones have the same possibilities,
// if another one have, go to next value
// init single possibiliites
// If skyscraper has no certain value yet
// Iterate through possible values of the skyscraper
// If no possibility for this num OR possibility not single, continue
// Once the column is completed, set the value of unique possibilities
// Do not change the height of a fixed skyscraper
// If it's the one which has unique possibility
// Set fixed height to this one
// Exit the loop since only one can be unique
// Check each row
// Do not change the height of a fixed skyscraper
/*void elimination(t_skyscraper **board, int size)
{	
	int *single_possibilities = malloc(sizeof(int) * size);

	for (int col = 0; col < size; col++)
	{
		for (int i = 0; i < size; i++)
		{
			single_possibilities[i] = -1;
		}
		for (int row = 0; row < size; row++)
		{
			t_skyscraper skyscraper = board[col][row];
			if (skyscraper.height == 0)
			{
				for (int i = 0; i < size; i++)
				{
					if (skyscraper.possibilities[i] == 0 || single_possibilities[i] == 0)	
						continue ;
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
		for (int i = 0; i < size; i++)
		{
			if (single_possibilities[i] >= 1)
			{
				for (int j = 0; j < size; j++)
				{
					t_skyscraper *skyscraper = &(board[col][j]);
					if (skyscraper -> height != 0)
						continue ;
					if (skyscraper -> possibilities[i] == i + 1)
					{
						skyscraper -> height = i + 1;	
						skyscraper -> fixed = 1;
						break ;
					}
				}
			}
		}
	}
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
					if (skyscraper -> height != 0)
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
}*/

void	elimination(t_skyscraper **board, int size)
{	
	int	i;
	int	col;
	int	*single_possibilities;

	i = 0;
	col = 0;
	*single_possibilities = malloc(sizeof(int) * size);
	while (col < size)
	{
		while (i < size)
		{
			single_possibilities[i] = -1;
			i++;
		}
		while (row < size)
		{
			skyscraper = board[col][row];
			if (skyscraper.height == 0)
			{
				while (i < size)
				{
					if (skyscraper.possibilities[i] == 0 || single_possibilities[i] == 0)	
					{
						i++;
						continue ;
					}
					if(skyscraper.possibilities[i] != single_possibilities[i])
					{
						single_possibilities[i] = skyscraper.possibilities[i];
					}
					else
					{
						single_possibilities[i] = 0;
					}
					i++;
				}
				row++;
			}
			col++;
		}
		for (int i = 0; i < size; i++)
		{
			if (single_possibilities[i] >= 1)
			{
				for (int j = 0; j < size; j++)
				{
					t_skyscraper *skyscraper = &(board[col][j]);
					if (skyscraper -> height != 0)
						continue ;
					if (skyscraper -> possibilities[i] == i + 1)
					{
						skyscraper -> height = i + 1;	
						skyscraper -> fixed = 1;
						break ;
					}
				}
			}
		}
	}
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
					if (skyscraper -> height != 0)
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
