#include "../ex02/ft_ultimate_range.c"
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
printf("================= EX 02 =================\n");


	int *t1;
	int *t2;
	int *t3;
	int *t4;
	int *t5;

	int **test = &t1;

	printf("Range (0, 10): Return: %d\n", ft_ultimate_range(test, 0, 10));
	print_arr(t1, 10);

	
	printf("\nRange (-123, -100): Return: %d\n", ft_ultimate_range(&t2, -123, -100));
	print_arr(t2, 23);
	
	printf("\nRange (10, 0): Return: %d\n", ft_ultimate_range(&t3, 10, 0));
	printf("pointer : %p\n\n", t3);
	
	printf("\nRange (1, 1): Return: %d\n", ft_ultimate_range(&t4, 1, 1));
	printf("pointer : %p\n\n", t4);
	
	printf("\nRange (0, 1): Return: %d\n", ft_ultimate_range(&t5, 0, 1));
	print_arr(t5, 1);
}
