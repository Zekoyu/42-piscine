void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	cur;
	int	i;
	int	smallest_index;
	int	smallest;

	cur = 0;
	i = 0;
	while (cur < size)
	{
		smallest = 2147483647;
		while (i < size)
		{
			if (tab[i] < smallest)
			{
				smallest = tab[i];
				smallest_index = i;
			}
			i++;
		}
		tab[smallest_index] = tab[cur];
		tab[cur] = smallest;
		i = ++cur;
	}
}
