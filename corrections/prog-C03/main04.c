#include "../ex04/ft_strstr.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{

	printf("=================== EX 04 ========================\n");

	printf("Input (\"\", \"Bonjour\") | Output: %s (Expected: %s)\n", ft_strstr("", "Bonjour"), strstr("", "Bonjour"));
	printf("Input (\"Salut\", \"Salute\") | Output: %s (Expected: %s)\n", ft_strstr("Salut", "Salute"), strstr("Salut", "Salute"));
	printf("Input (\"Non ?\", \"\") | Output: %s (Expected: %s)\n", ft_strstr("Non ?", ""), strstr("Non ?", ""));
	printf("Input (\"Ah enfin Ah\", \"Ah \") | Output: %s<== (Expected: %s<==)\n", ft_strstr("Ah enfin Ah", "Ah "), strstr("Ah enfin Ah", "Ah "));
	printf("Input (\"Alors ca trouve \\xc8 ou pas ? >>_>>\", \"\\xc8\") | Output: %s<== (Expected: %s<==)\n", ft_strstr("Alors ca trouve \xc8 ou pas ? >>_>>", "\xc8"), strstr("Alors ca trouve \xc8 ou pas ? >>_>>", "\xc8"));
}
