#include "helper.h"

int	find_num(char *str, int length)
{
	int	i;
	int	j;
	int	k;
	int	num;
	int	pow;

	num = 0;
	i = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0' && i < length)
		i++;
	while (--i >= 0)
	{
		pow = 1;
		k = 0;
		while (k < j)
		{
			pow *= 10;
			k++;
		}
		num += (str[i] - 48) * pow;
		j++;
	}
	return (num);
}
