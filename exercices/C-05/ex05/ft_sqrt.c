int	ft_sqrt(int nb);

// (nb/2)^2 > nb 	for every nb > 4
// We then find a perfect square close (but <) to nb
// Next we simply try every single number between n and sqrt(nb)
// If n^2 is superior to nb, ie means it has no perfect sqrt
// Else if n^2 == nb, it means n is the perfect sqrt of nb
// Since it then iterate n++ while n^2 < nb, it also supports 0, 1 and 4

int	ft_sqrt(int nb)
{
	unsigned long	n;

	if (nb < 0)
		return (0);
	n = nb / 2;
	while (n * n > (unsigned long) nb)
		n /= 2;
	while (n * n < (unsigned long) nb)
		n++;
	if (n * n == (unsigned long) nb)
		return (n);
	return (0);
}
