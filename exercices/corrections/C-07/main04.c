#include "../ex04/ft_convert_base.c"
#include "../ex04/ft_convert_base2.c"
#include <stdio.h>

int main()
{
printf("================= EX 04 =================\n");

	printf("Convert base (\"FF\", \"0123456789ABCDEF\", \"0123456789\"): %s (Expected 255)\n", ft_convert_base("FF", "0123456789ABCDEF", "0123456789"));
	printf("Convert base (\"-Crakito\", \"Crakito\", \"Crakito\"): %s (Expected -rackito (?))\n", ft_convert_base("-Crakito", "Crakito", "Crakito"));
	printf("Convert base (\"-123456789F\", \"0123456789\", \"0123456789\"): %s (Expected -123456789)\n", ft_convert_base("-123456789F", "0123456789", "0123456789"));
	printf("Convert base (\"-crackito\", \"crackito\", \"crackito\"): %s (Expected NULL)\n", ft_convert_base("-crackito", "crackito", "crackito"));
	printf("Convert base (\"0\", \"0123456789\", \"poneyvif\"): %s (Expected p)\n", ft_convert_base("0", "0123456789", "poneyvif"));
	printf("Convert base (\"-0\", \"0123456789\", \"poneyvif\"): %s (Expected p)\n", ft_convert_base("-0", "0123456789", "poneyvif"));
	printf("Convert base (\"1111111111111111111111111111111\", \"01\", \"0123456789\"): %s (Expected 2147483647)\n", ft_convert_base("1111111111111111111111111111111", "01", "0123456789"));
	printf("Convert base (\"-10000000000000000000000000000000\", \"01\", \"0123456789\"): %s (Expected -2147483648)\n", ft_convert_base("-10000000000000000000000000000000", "01", "0123456789"));
	printf("Convert base (\"CCC\", \"Crakito\", \"0123456789\"): %s (Expected 0)\n", ft_convert_base("CCC", "Crakito", "0123456789"));

}
