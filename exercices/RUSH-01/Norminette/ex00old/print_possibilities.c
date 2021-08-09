// If unsure value, print possibilities
// If known value, print value directly
/*void	print_possibilities(t_skyscraper **board, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col ++)
		{
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
			else
			{
				printf("%s", "{");
				for (int i = 0; i < size; i++)
				{
					if (i == size / 2)
						printf("%d", board[col][row].height);
					else
						printf("%s", "   ");
				}
				printf("%s", " }");
			}
		}
		printf("%s", "\n");
	}
}*/

void	print_possibilities(t_skyscraper **board, int size)
{
	int	row;
	int	col;
	int	j;
	int	i;

	row = 0;
	col = ;
	j = ;
	i = 0;
	while (row < size)
	{
		while (col < size)
		{
			if (board[col][row].height == 0)
			{
				printf("%s", "[");
				while (j < size)
				{
					if (j != size - 1)
						printf("%d, ", board[col][row].possibilities[j]);
					else
						printf("%d, ", board[col][row].possibilities[j]);
					j++;
				}
				printf("%s", "]");
			}
			else
			{
				printf("%s", "{");
				while (i < size)
				{
					if (i == size / 2)
						printf("%d", board[col][row].height);
					else
						printf("%s", " ");
					i++;
				}
				printf("%s", "}");
			}
			col++;
		}
		printf("%s", "\n");
		row++;
	}
}
