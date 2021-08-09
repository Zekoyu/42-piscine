int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	factorial;

	if (nb < 0)
		return (0);
	factorial = 1;
	i = 1;
	while (i < nb)
	{
		i++;
		factorial *= i;
	}
	return (factorial);
}
