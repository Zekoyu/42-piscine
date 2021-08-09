void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	buffer;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		buffer = tab[start];
		tab[start] = tab[end];
		tab[end] = buffer;
		start++;
		end--;
	}
}
