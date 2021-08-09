#include "../ex06/ft_is_prime.c"
#include <stdio.h>
#include <time.h>

int main()
{
	printf("================= EX 06 =================\n");

	clock_t begin = clock();	
	printf("Is prime (0) : %d (expect 0)\n", ft_is_prime(0));
	printf("Is prime (1) : %d (expect 0)\n", ft_is_prime(1));
	printf("Is prime (2) : %d (expect 1)\n", ft_is_prime(2));
	printf("Is prime (4) : %d (expect 0)\n", ft_is_prime(4));
	printf("Is prime (5) : %d (expect 1)\n", ft_is_prime(5));
	printf("Is prime (9) : %d (expect 0)\n", ft_is_prime(9));
	printf("Is prime (109) : %d (expect 1)\n", ft_is_prime(109));
	printf("Is prime (2147483647) : %d (expect 1)\n", ft_is_prime(2147483647));

	clock_t end = clock();
	double time = (double) (end - begin) / CLOCKS_PER_SEC;

	printf("Exec time: %.2fsec. (Expected around 3 sec. ?)\n", time);
}
