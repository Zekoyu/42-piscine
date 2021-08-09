#include "../ex00/ft_strlen.c"

#include <stdio.h>

int	main(void)
{
	printf("=================== EX 00 ========================\n");
	
	printf("Input(\"\") | Return:%d\n", ft_strlen(""));
	printf("Input(\"1234567890\") |Return:%d\n", ft_strlen("1234567890"));
	printf("Input(\"Ca marche ?\") | Return:%d\n", ft_strlen("Ca marche ?"));
	printf("Input(\"test \\xc8 \\t10\") | Return:%d\n", ft_strlen("test \xc8 \t10"));
}
