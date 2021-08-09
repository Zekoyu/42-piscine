#include <stdlib.h>

#include "olivia.h"

char	*get_associated_data(char *number, t_dict_value *dict_values)
{
	int	i;

	i = 0;
	while (!(dict_values[i].number[0] == '\0' && dict_values[i].data == NULL))
	{
		if (ft_strcmp(dict_values[i].number, number) == 0)
			return (dict_values[i].data);
		i++;
	}
	return (NULL);
}

char	*get_char_associated_data(char number, t_dict_value *dict_values)
{
	int		i;
	char	*num_str;

	num_str = malloc (sizeof (char) * 2);
	num_str[0] = number;
	num_str[1] = '\0';
	i = 0;
	while (!(dict_values[i].number[0] == '\0' && dict_values[i].data == NULL))
	{
		if (ft_strcmp(dict_values[i].number, num_str) == 0)
		{
			free(num_str);
			return (dict_values[i].data);
		}
		i++;
	}
	free(num_str);
	return (NULL);
}
