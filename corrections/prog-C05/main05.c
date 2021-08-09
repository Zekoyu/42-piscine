#include "../ex05/ft_sqrt.c"
#include <stdio.h>

int main()
{
	printf("================= EX 03 =================\n");
	
	printf("sqrt(0): %d (expected 0)\n", ft_sqrt(0));
	printf("sqrt(25): %d (expected 5)\n", ft_sqrt(25));
	printf("sqrt(24): %d (expected 0)\n", ft_sqrt(2147483647));
	printf("sqrt(-1): %d (expected ?)\n", ft_sqrt(-1));
	printf("sqrt(-2147483648): %d (expected 0)\n", ft_sqrt(-2147483648));
	printf("sqrt(-2147): %d (expected 0)\n", ft_sqrt(-2147));
	printf("sqrt(100000000): %d (expected 10000)\n", ft_sqrt(100000000));
	printf("sqrt(4): %d (expected 2)\n", ft_sqrt(4));
	printf("sqrt(1): %d (expected 1)\n", ft_sqrt(1));
}
