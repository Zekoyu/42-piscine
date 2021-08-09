#include "../ex12/ft_print_memory.c"

#include <stdio.h>

char test[92]= "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
unsigned int testlen = 92;

int main()
{
	printf("=================== EX 12 ========================\n");	
	printf("Test avec l'exemple du sujet: \n\n");
	ft_print_memory(test, testlen);

	printf("\nTest avec size 0 (deux sauts de lignes apres cette ligne): \n\n");
    ft_print_memory(test, 0);
	printf("<===FINITO\n");

	printf("\nTest (\"te\\xc8st\\x7f, 5): \n\n");
    ft_print_memory("te\xc8st\x7f", 5);
	printf("<===FINITO\n");
}
