// If the number % divisor == 1, it means it might be prime
// Else if the modulo == 0, it means the number is not, so return
// We repeat this step until divisor == 1
// If divisor reaches 1, it means the number is prime
// We can start with divisor = 2 (so that even nums are directly bypassed etc.)
// and loop until at most nb/2 because nb cannot divide
// by more than nb/2 (ex 20 cannot divide by more than 10)
// We do nb++ until it is a prime num
// Except we have div1 = 2 and div2 = nb/2, because it's faster
// To loop while div1 <= div2 (div1++; div2--)

int	is_prime(int nb)
{
	int	div1;
	int	div2;

	div1 = 2;
	div2 = nb / 2;
	if (nb <= 1)
		return (0);
	while (div1 <= div2)
	{
		if ((nb % div1 == 0 || nb % div2 == 0) && (div1 != nb && div2 != nb))
			return (0);
		div1++;
		div2--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!is_prime(nb))
	{
		if (nb > 2147483629)
			return (2147483647);
		nb++;
	}
	return (nb);
}
