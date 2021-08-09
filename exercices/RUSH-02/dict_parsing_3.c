#include <stdlib.h>

#include "olivia.h"

int	get_trim_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i--;
	return (i);
}

int	get_trim_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (i);
}

// "   512" => 512
int	str_index_without_spaces(char *number, int number_len)
{
	int		i;

	i = 0;
	while ((number[i] == ' ' || number[i] == '\t' || number[i] == '\v')
		&& i < number_len)
	{
		i++;
	}
	return (i);
}

// 000512 => 512
char	*trim_zeroes(char *number, int number_len)
{
	char	*trimmed_num;
	int		i;
	int		j;
	int		count;

	i = 0;
	while (number[i] == '0')
		i++;
	if (i == number_len)
	{
		trimmed_num = malloc (sizeof (char) * 2);
		trimmed_num[0] = '0';
		trimmed_num[1] = '\0';
		return (trimmed_num);
	}
	count = number_len - i;
	trimmed_num = malloc (sizeof (char) * (count + 1));
	j = 0;
	while (i < number_len)
	{
		trimmed_num[j++] = number[i++];
	}
	trimmed_num[j] = '\0';
	return (trimmed_num);
}

// "  00512" => 512
char	*trim_zeroes_and_spaces(char *number, int number_len)
{
	char	*trimmed_num;
	int		offset;

	offset = str_index_without_spaces(number, number_len);
	trimmed_num = trim_zeroes(&(number[offset]), number_len - offset);
	return (trimmed_num);
}
