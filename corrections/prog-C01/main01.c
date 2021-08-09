#include "../ex01/ft_ultimate_ft.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 01 ========================\n");
	int test = 123456;
	int *test1 = &test;
	int **test2 = &test1;
	int ***test3 = &test2;
	int ****test4 = &test3;
	int *****test5 = &test4;
	int ******test6 = &test5;
	int *******test7 = &test6;
	int ********test8 = &test7;
    int *********test9 = &test8;
	
	ft_ultimate_ft(test9);
    printf("Input 123456 | Output:%d\n", test);

    test = -987654;
    ft_ultimate_ft(test9);
    printf("Input -987654 | Output:%d\n", test);	
}
