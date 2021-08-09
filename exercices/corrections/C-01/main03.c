#include "../ex03/ft_div_mod.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 03 ========================\n");

	int test1 = 10;
	int test2 = 2;

	int div;
	int mod;

	ft_div_mod(test1, test2, &div, &mod);
	printf("Input: (10, 2) | Output: (%d, %d)\n", div, mod);

	test1 = -20;
    test2 = 6;

    ft_div_mod(test1, test2, &div, &mod);
    printf("Input: (-20, 6) | Output: (%d, %d)\n", div, mod);
}
