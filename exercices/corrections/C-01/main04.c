#include "../ex04/ft_ultimate_div_mod.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 04 ========================\n");

	int test1 = 10;
	int test2 = 2;

	ft_ultimate_div_mod(&test1, &test2);
	printf("Input: (10, 2) | Output: (%d, %d)\n", test1, test2);

	test1 = -20;
    test2 = 6;

    ft_ultimate_div_mod(&test1, &test2);
    printf("Input: (-20, 6) | Output: (%d, %d)\n", test1, test2);
}
