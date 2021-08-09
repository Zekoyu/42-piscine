#include "../ex06/ft_str_is_printable.c"

#include<stdio.h>

int main()
{
	printf("=================== EX 06 ========================\n");
	
	char c[] = {'T', ' ', 10};

	printf("Is printable(\"\") | Output: %d\n", ft_str_is_printable(""));
	printf("Is printable(\"T <nl>\") | Output: %d\n", ft_str_is_printable(c));
	printf("Is printable(\"bah non ?\\n\") | Output: %d\n", ft_str_is_printable("bah non ?\n"));
	printf("Is printable(\"Ceci est un test ? Je crois 0ui\") | Output: %d\n", ft_str_is_printable("Ceci est un test ? Je crois 0ui"));
}
