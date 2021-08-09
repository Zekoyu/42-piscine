#include <stdlib.h>

#include "olivia.h"

void	init_threesomes(t_threesome *threesomes, int threesomes_count)
{
	int	i;

	i = 0;
	while (i < threesomes_count)
	{
		threesomes[i].hundreds = '0';
		threesomes[i].tens = '0';
		threesomes[i].units = '0';
		threesomes[i].index = 0;
		i++;
	}
}

// What a split name !
void	fill_threesome(t_threesome *threesomes_list, int threesomes_count,
	char *str, int str_len)
{
	int	i;
	int	j;

	i = threesomes_count - 1;
	j = str_len - 1;
	while (i >= 0)
	{
		threesomes_list[i].index = threesomes_count - 1 - i;
		threesomes_list[i].units = str[j--];
		if (j < 0)
			break ;
		threesomes_list[i].tens = str[j--];
		if (j < 0)
			break ;
		threesomes_list[i].hundreds = str[j--];
		if (j < 0)
			break ;
		i--;
	}
}

// Index 0 = last threesome
// List in the reading order, but index reverse (starting from N to 0)
// Remove starting zeroes (not for last threesome) : 0000100 => 100 | 00 => 00
t_threesome	*parse_to_threesomes(char *str)
{
	t_threesome	*threesomes_list;
	int			str_len;
	int			threesomes_count;
	int			i;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len - 3)
	{
		if (*str == '0')
			str++;
		else
			break ;
		i++;
	}
	str_len = ft_strlen(str);
	threesomes_count = str_len / 3;
	if (str_len % 3 > 0)
		threesomes_count++;
	threesomes_list = malloc(sizeof (t_threesome) * threesomes_count);
	init_threesomes(threesomes_list, threesomes_count);
	fill_threesome(threesomes_list, threesomes_count, str, str_len);
	return (threesomes_list);
}
