#include "../ex08/ft_sort_int_tab.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 08 ========================\n");

	int test1[] = {5, 3, 1, 4, 2};
	int test2[] = {-5, 42, 8, -20};

	ft_sort_int_tab(test1, 5);
	ft_sort_int_tab(test2, 4);

	printf("Input {5, 3, 1, 4, 2} | Output: {");
	for (int i = 0; i < 4; i++) {
		printf("%d, ", test1[i]);
	}
	printf("%d}\n", test1[4]);


	printf("Input {-5, 42, 8, -20} | Output: {");
    for (int i = 0; i < 3; i++) {
        printf("%d, ", test2[i]);
    }
    printf("%d}\n", test2[3]);
}
