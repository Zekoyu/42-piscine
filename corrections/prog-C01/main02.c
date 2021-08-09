#include "../ex02/ft_swap.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 02 ========================\n");
	
	int test1 = 50;
	int test2 = -123;
	ft_swap(&test1, &test2);

	printf("Input (50, -123) | Output:(%d, %d)\n", test1, test2);
	
	test1 = -2147483648;
	test2 = 2147483647;
	ft_swap(&test1, &test2);

	printf("Input (-2147483648, 2147483647) | Output:(%d, %d)\n", test1, test2);
}
