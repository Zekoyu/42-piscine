#include "../ex03/ft_str_is_numeric.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 03 ========================\n");

	printf("Is numeric(\"\") | Output: %d\n", ft_str_is_numeric(""));
	printf("Is numeric(\"0 + 0 = la tete a toto\") | Output: %d\n", ft_str_is_numeric("0 + 0 = la tete a toto"));
	printf("Is numeric(\"69420\") | Output: %d\n", ft_str_is_numeric("69420"));
	printf("Is numeric(\"S@lut\") | Output: %d\n", ft_str_is_numeric("S@lut"));
}
