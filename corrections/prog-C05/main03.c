#include "../ex03/ft_recursive_power.c"
#include <stdio.h>

int main()
{
	printf("================= EX 03 =================\n");
	
	printf("Pow (0, 0): %d (expect 1)\n", ft_recursive_power(0,0));
	printf("Pow (1, 3): %d (expect 1)\n", ft_recursive_power(1,3));
	printf("Pow (2, 3): %d (expect 8)\n", ft_recursive_power(2,3));
	printf("Pow (0, 3): %d (expect 0)\n", ft_recursive_power(0,3));
	printf("Pow (0, -1): %d (expect 0)\n", ft_recursive_power(0, -1));
	printf("Pow (5, -3): %d (expect 0)\n", ft_recursive_power(5, -3));
	printf("Pow (-5, 8): %d (expect 390625)\n", ft_recursive_power(-5, 8));
	printf("Pow (-2, 10): %d (expect 1024)\n", ft_recursive_power(-2, 10));
	printf("Pow (-1234, 0): %d (expect 1)\n", ft_recursive_power(-1234, 0));
	printf("Pow (1234, 1): %d (expect 1234)\n", ft_recursive_power(1234, 1));

}
