#include "../ex04/ft_fibonacci.c"
#include <stdio.h>

int main()
{
	printf("================= EX 04 =================\n");
	
	printf("Fibonnaci(0): %d (expected 0)\n", ft_fibonacci(0));
	printf("Fibonnaci(1): %d (expected 1)\n", ft_fibonacci(1));
	printf("Fibonnaci(2): %d (expected 1)\n", ft_fibonacci(2));
	printf("Fibonnaci(3): %d (expected 2)\n", ft_fibonacci(3));
	printf("Fibonnaci(10): %d (expected 55)\n", ft_fibonacci(10));
	printf("Fibonnaci(20): %d (expected 6765)\n", ft_fibonacci(20));

}
