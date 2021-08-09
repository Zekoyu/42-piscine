#include "../ex11/ft_putstr_non_printable.c"

#include<stdio.h>

int	main(void)
{
	printf("=================== EX 11 ========================\n");

	
	printf("Input(\'Coucou\\ntu vas bien ?  | Output (newline):\n");
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	printf("<==FINITO\n\n");

	printf("Input(\'Comment\\ton\\nquitte \\xc8vim\\x7f ?  | Output (newline):\n");
	ft_putstr_non_printable("Comment\ton\nquitte \xc8vim\x7f ?");
 	printf("<==FINITO");

}
