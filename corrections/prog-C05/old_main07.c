#include "../ex07/ft_find_next_prime.c"
#include <stdio.h>
#include <time.h>

int main()
{
	printf("================= EX 07 =================\n");

	clock_t start = clock();

	printf("Next prime (0) : %d (expect 2)\n", ft_find_next_prime(0));
	printf("Next prime (-500) : %d (expect maybe 2 ?)\n", ft_find_next_prime(-500));
	printf("Next prime (1) : %d (expect 2)\n", ft_find_next_prime(1));
	printf("Next prime (2) : %d (expect 2)\n", ft_find_next_prime(2));
	printf("Next prime (4) : %d (expect 5)\n", ft_find_next_prime(4));
	printf("Next prime (5) : %d (expect 5)\n", ft_find_next_prime(5));
	printf("Next prime (9) : %d (expect 11)\n", ft_find_next_prime(9));
	printf("Next prime (110) : %d (expect 113)\n", ft_find_next_prime(110));
	printf("Next prime (2000000000) : %d (expect 2000000011)\n", ft_find_next_prime(2000000000));
	printf("Next prime (2147483647) : %d (expect 2147483647)\n", ft_find_next_prime(2147483647));

	clock_t end = clock();
	double exec_time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("Exec time: %.2fsec. (expected around 6sec ?)\n", exec_time);
}
