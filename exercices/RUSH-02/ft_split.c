#include <stdlib.h>

int	char_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_s_co(char *str, char *charset)
{
	int	i;
	int	j;
	int	str_count;

	i = 0;
	str_count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (!char_in_charset(str[i + j], charset) && str[i + j] != '\0')
		{
			if (j == 0)
				str_count++;
			j++;
		}
		i += j;
		i++;
	}
	return (str_count);
}

char	*create_sub_str(char *str, char *charset, int index)
{
	char	*substr;
	int		substrlen;
	int		i;
	int		j;

	i = index;
	j = 0;
	substrlen = 0;
	while (str[i] != '\0' && !char_in_charset(str[i], charset))
	{
		substrlen++;
		i++;
	}
	substr = malloc(sizeof (char *) * substrlen + 1);
	i = index;
	while (str[i] != 0 && !char_in_charset(str[i], charset))
	{
		substr[j] = str[i];
		j++;
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

// j++ then 'i + j - 1' to gain lines
char	**get_split_values(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split_values;
	char	*sub_string;
	int		split_values_index;

	split_values = malloc (sizeof(char *) * (get_s_co(str, charset) + 1));
	split_values_index = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (!char_in_charset(str[i + j], charset) && str[i + j] != '\0')
		{
			if (j++ == 0)
				sub_string = create_sub_str(str, charset, (i + j - 1));
		}
		if (j != 0)
			split_values[split_values_index++] = sub_string;
		if (j == 0)
			j = 1;
		i += j;
	}
	split_values[split_values_index] = 0;
	return (split_values);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;

	if (str == NULL || charset == NULL )
	{
		res = malloc(sizeof (char *));
		res[0] = 0;
		return (res);
	}
	res = get_split_values(str, charset);
	return (res);
}
