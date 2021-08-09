#include "../ex05/ft_atoi_base.c"

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("=================== EX 05 ========================\n");
	
	printf("atoi_base (\"10120120210210\", \"01\") : %d (Expected 5 (101 in binary)\n", ft_atoi_base("10120120210210", "01"));
	printf("atoi_base (\"-2147483648\", \"0123456789\") : %d (Expected -2147483648)\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("atoi_base (\"01010101010101010101\", \"01\") : %d (Expected 349525)\n", ft_atoi_base("01010101010101010101", "01"));
	printf("atoi_base (\"222111000\", \"012\") : %d (Expected 19305)\n", ft_atoi_base("222111000", "012"));
	printf("atoi_base (\"012345670\", \"01234567\") : %d (Expected 2739128)\n", ft_atoi_base("012345670", "01234567"));
	printf("atoi_base (\"-CrackitoC\", \"Crackito\") : %d (Expected -2739128)\n", ft_atoi_base("-CrackitoC", "Crackito"));
	printf("atoi_base (\"012\", \"0123 \") : %d (Expected 0)\n", ft_atoi_base("012", "0123 "));
	printf("atoi_base (\"-123\", \"+123\") : %d (Expected 0)\n", ft_atoi_base("-123", "+123"));
	printf("atoi_base (\"test\", \"\\ntest\\t\") : %d (Expected 0)\n", ft_atoi_base("test", "\ntest\t"));
}
