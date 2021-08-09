void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;
	int	val;

	i = 0;
	while (i < length)
	{
		val = tab[i];
		(*f)(val);
		i++;
	}
}
