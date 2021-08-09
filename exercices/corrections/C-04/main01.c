#include "../ex01/ft_putstr.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 01 ========================\n");

	printf("Putstr (\"Salut 123\"), output:\n");
	ft_putstr("Salut 123");
	printf("<==FINITO\n");

	printf("Putstr (\"Test \\t oui ?\\n non ?\"), output:\n");
	ft_putstr("Test \t oui ?\n non ?");	
	printf("<==FINITO\n");

	printf("Putstr (\"\\xc8\"), output:\n");
	ft_putstr("\xc8");
	printf("<==FINITO\n");
}
