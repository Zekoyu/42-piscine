#include "../ex02/ft_str_is_alpha.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 02 ========================\n");

	printf("Is alpha(\"\") | Output: %d\n", ft_str_is_alpha(""));
	printf("Is alpha(\"TeSt\") | Output: %d\n", ft_str_is_alpha("TeSt"));
	printf("Is alpha(\"B0njour{}\") | Output: %d\n", ft_str_is_alpha("B0njour{}"));
	printf("Is alpha(\"S@lut\") | Output: %d\n", ft_str_is_alpha("S@lut"));
}
