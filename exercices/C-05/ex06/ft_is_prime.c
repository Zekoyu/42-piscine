// If the number % divisor == 1, it means it might be prime
// Else if the modulo == 0, it means the number is not, so return
// We repeat this step until divisor > nb/2
// If divisor reaches nb/2 without return, it means the number is prime
// We can start with divisor = 2 (so that even nums are popped out immediately)
// and loop until divisor > nb/2 because nb cannot divide
// by more than nb/2 (ex 20 cannot divide by more than 10)

int	ft_is_prime(int nb)
{
	int	div1;
	int	div2;

	div1 = 2;
	div2 = nb / 2;
	if (nb <= 1)
		return (0);
	while (div1 <= div2)
	{
		if (nb % div1 == 0 || nb % div2 == 0)
			return (0);
		div1++;
		div2--;
	}
	return (1);
}
