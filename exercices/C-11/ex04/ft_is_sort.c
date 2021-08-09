int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	reference;
	int	val;

	reference = 0;
	i = 0;
	while (++i < length)
	{
		val = (*f)(tab[i - 1], tab[i]);
		if (reference == 0)
		{
			if (val < 0)
				reference = -1;
			else if (val > 0)
				reference = 1;
		}
		else
		{
			if (reference > 0 && val < 0)
				return (0);
			else if (reference < 0 && val > 0)
				return (0);
		}
	}
	return (1);
}
