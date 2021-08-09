#include "../ex02/ft_iterative_power.c"
#include <stdio.h>

int main()
{
	printf("================= EX 02 =================\n");
	
	printf("Pow (0, 0): %d (expect 1)\n", ft_iterative_power(0,0));
	printf("Pow (1, 3): %d (expect 1)\n", ft_iterative_power(1,3));
	printf("Pow (2, 3): %d (expect 8)\n", ft_iterative_power(2,3));
	printf("Pow (0, 3): %d (expect 0)\n", ft_iterative_power(0,3));

}
