#include "../ex00/ft_ft.c"

#include<stdio.h>

int	main(void)
{
	int test = 123456;
	printf("=================== EX 00 ========================\n");
	ft_ft(&test);
	printf("Input 123456 | Output:%d\n", test);
	test = -987654;
	ft_ft(&test);
	printf("Input -987654 | Output:%d\n", test);
}
