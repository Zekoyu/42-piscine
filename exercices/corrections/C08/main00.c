#include "../ex00/ft.h"
#include <stdio.h>

int main()
{
	printf("================= EX 00 =================\n");

	int t1 = 1;
	int t2 = 2;

	ft_putchar(' ');
	ft_swap(&t1, &t2);
	ft_putstr("test");
	ft_strlen("test");
	ft_strcmp("1", "2");
}

void	ft_putchar(char c)
{
	printf("Putchar\n");
	(void) c;
}

void	ft_swap(int *a, int *b)
{
	printf("Swap\n");
	(void) a;
	(void) b;
}

void	ft_putstr(char *str)
{
	printf("Putstr\n");
	(void) str;
}

int		ft_strlen(char *str)
{
	printf("Strlen\n");
	(void) str;
	return 1;
}

int		ft_strcmp(char *s1, char *s2)
{
	printf("Strcmp\n");
	(void) s1;
	(void) s2;
	return 1;
}