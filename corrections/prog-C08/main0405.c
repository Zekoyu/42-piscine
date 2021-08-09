#include "../ex04/ft_strs_to_tab.c"
#include "../ex05/ft_show_tab.c"
#include "./ft_stock_str.h"
#include <stdio.h>

int main()
{
	printf("================ EX 04/05 ================\n");

	printf("Create and show tab {\"Salut\", \"Test\", \"oui  \"} :\n");
	char **test = malloc (sizeof (char *) * 3);
	test[0] = "Salut";
	test[1] = "Test";
	test[2] = "oui  ";
	ft_show_tab(ft_strs_to_tab(3, test));
}
