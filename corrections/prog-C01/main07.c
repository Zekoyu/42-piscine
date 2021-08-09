#include "../ex07/ft_rev_int_tab.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 07 ========================\n");

	int test1[] = {1, 2, 3};
	int test2[] = {-5, 42, 8, -20};

	ft_rev_int_tab(test1, 3);
	ft_rev_int_tab(test2, 4);

	printf("Input {1, 2, 3} | Output: {");
	for (int i = 0; i < 2; i++) {
		printf("%d, ", test1[i]);
	}
	printf("%d}\n", test1[2]);


	printf("Input {-5, 42, 8, -20} | Output: {");
    for (int i = 0; i < 3; i++) {
        printf("%d, ", test2[i]);
    }
    printf("%d}\n", test2[3]);
}
