#include "../ex03/ft_atoi.c"

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{

	printf("=================== EX 03 ========================\n");
	printf("Input(\"Salut ceci est un test 1234\") | Return:%d \n", ft_atoi("Salut ceci est un test 1234"));
	printf("Input(\"    ---+--+1234ab567\") | Return:%d \n", ft_atoi("    ---+--+1234ab567"));
	printf("Input(\"\\f\\n\\r\\t\\v   +-+-123\") | Return:%d \n", ft_atoi("\f\n\r\t\v  +-+-123"));
	printf("Input(\"  +-+- 123\") | Return:%d \n", ft_atoi("  +-+- 123"));
	printf("Input(\"123\") | Return:%d \n", ft_atoi("123"));
	printf("Input(\"\\t321\") | Return:%d \n", ft_atoi("\t321"));
	printf("Input(\"+\\t321\") | Return:%d \n", ft_atoi("+\t321"));
	printf("Input(\"\\t-21\") | Return:%d \n", ft_atoi("\t-21"));
}
