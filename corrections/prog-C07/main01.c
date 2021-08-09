#include "../ex01/ft_range.c"
#include <stdio.h>


void	print_arr(int *tab, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	printf("%d\n", tab[i]);
}

int main()
{
printf("================= EX 01 =================\n");


	printf("Range (0, 10):\n");
	print_arr(ft_range(0, 10), 10);
	
	printf("Range (-123, -100):\n");
	print_arr(ft_range(-123, -100), 23);
	
	printf("Range (10, 0):   ");
	printf("pointer : %p\n", ft_range(10, 0));
	
	printf("Range (1, 1):  ");
	printf("pointer : %p\n", (ft_range(1 ,1)));
	
	printf("Range (0, 1):\n");
	print_arr(ft_range(0, 1), 1);
}
