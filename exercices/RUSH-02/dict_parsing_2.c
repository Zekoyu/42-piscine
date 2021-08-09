#include <stdlib.h>

#include "olivia.h"

// " TEST "
//   ^  ^
//   1  4
// Length (4 - 1) + 1 ( + 1 more for '\0')
void	set_dict_value(t_dict_value *dict_value, char *number,
	int number_len, char *data)
{
	char	*num_value;
	char	*data_value;
	int		data_start;
	int		data_end;
	int		i;

	num_value = trim_zeroes_and_spaces(number, number_len);
	data_start = get_trim_start(data);
	data_end = get_trim_end(data);
	data_value = malloc (sizeof (char) * (data_end - data_start + 2));
	i = 0;
	while (data_start <= data_end)
		data_value[i++] = data[data_start++];
	dict_value->number = num_value;
	dict_value->data = data_value;
}

// Convert dict line to dict_value (left value & right value)
// &line[i + 1] = right value (after ':')
void	parse_line(char *line, t_dict_value *dict_value)
{
	int		i;
	int		num_size;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i] != '\0')
		i++;
	if (i == 0 || line[i] == '\0')
	{
		dict_value->data = NULL;
		dict_value->number = NULL;
		return ;
	}
	num_size = i;
	while (line[i] != ':' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		dict_value->data = NULL;
		dict_value->number = NULL;
		return ;
	}
	set_dict_value(dict_value, &(line[0]), num_size, &(line[i + 1]));
}

void	free_dict_values(t_dict_value *dict_values, int dict_values_count)
{
	int	i;

	i = 0;
	while (i < dict_values_count)
	{
		if (dict_values[i].number != 0)
			free(dict_values[i].number);
		if (dict_values[i].data != 0)
			free(dict_values[i].data);
		i++;
	}
	free(dict_values);
}

// Set last elt values to NULL and NULL
t_dict_value	*parse_lines(char **lines, int values_count)
{
	int				i;
	t_dict_value	*dict_values;

	dict_values = malloc (sizeof (t_dict_value) * (values_count + 1));
	i = 0;
	while (i < values_count)
	{
		dict_values[i].number = 0;
		dict_values[i++].data = 0;
	}
	i = 0;
	while (i < values_count)
	{
		parse_line(lines[i], &(dict_values[i]));
		if (dict_values[i].data == NULL && dict_values[i].number == NULL)
		{
			free_dict_values(dict_values, values_count);
			return (NULL);
		}
		i++;
	}
	dict_values[i].number = "";
	dict_values[i].data = NULL;
	return (dict_values);
}
