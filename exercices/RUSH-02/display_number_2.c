#include <stdlib.h>

#include "olivia.h"

int	is_empty_threesome(t_threesome threesome)
{
	if (threesome.hundreds == '0' && threesome.tens == '0'
		&& threesome.units == '0')
		return (1);
	return (0);
}

// Index 1 => 1000 (1 + i*3 zeroes + '\0')
char	*get_multiple(int index)
{
	int		i;
	int		char_count;
	char	*res;

	char_count = (index * 3) + 2;
	res = malloc (sizeof (char) * char_count);
	i = 0;
	res[i++] = '1';
	while (i < char_count - 1)
		res[i++] = '0';
	res[i] = '\0';
	return (res);
}

// Convert 7 to 70, etc.
char	*get_tens(char tens_number)
{
	char	*res;

	res = malloc (sizeof (char) * 3);
	res[0] = tens_number;
	res[1] = '0';
	res[2] = '\0';
	return (res);
}

char	*get_special_tens(char tens, char units)
{
	char	*res;

	res = malloc(sizeof (char) * 3);
	res[0] = tens;
	res[1] = units;
	res[2] = '\0';
	return (res);
}
