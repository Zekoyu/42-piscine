#include <unistd.h>
#include <stdlib.h>

#include "olivia.h"

void	print_first_part(char hundreds, char tens, char units,
						t_dict_value *dict_values)
{
	char	*tmp_val;

	if (hundreds != '0')
	{
		ft_putstr(get_char_associated_data(hundreds, dict_values));
		ft_putstr(" ");
		ft_putstr(get_associated_data("100", dict_values));
		ft_putstr(" ");
		if (tens != '0' || units != '0')
			ft_putstr("and ");
	}
	if (tens != '0' && tens != '1')
	{
		tmp_val = get_tens(tens);
		ft_putstr(get_associated_data(tmp_val, dict_values));
		ft_putstr("-");
		free(tmp_val);
	}
	else if (tens == '1')
	{
		tmp_val = get_special_tens(tens, units);
		ft_putstr(get_associated_data(tmp_val, dict_values));
		ft_putstr(" ");
		free(tmp_val);
	}
}

void	print_threesome_values(t_threesome threesome, t_dict_value *dict_values)
{
	char	hundreds;
	char	tens;
	char	units;

	hundreds = threesome.hundreds;
	tens = threesome.tens;
	units = threesome.units;
	print_first_part(hundreds, tens, units, dict_values);
	if (hundreds == '0' && tens == '0')
	{
		ft_putstr(get_char_associated_data(units, dict_values));
		if (threesome.index != 0)
			ft_putstr(" ");
	}
	else if (tens != '1' && units != '0')
	{
		ft_putstr(get_char_associated_data(units, dict_values));
		if (threesome.index != 0)
			ft_putstr(" ");
	}
}

int	is_no_good(t_threesome *threesomes_list, t_dict_value *dict_values)
{
	int				i;
	char			*current_multiple;
	char			*current_data;
	t_threesome		last_threesome;
	t_threesome		current_threesome;

	i = 0;
	while (threesomes_list[i].index != 0)
	{
		current_threesome = threesomes_list[i];
		current_multiple = get_multiple(current_threesome.index);
		current_data = get_associated_data(current_multiple, dict_values);
		if (current_data == NULL)
			return (1);
		free(current_multiple);
		i++;
	}
	last_threesome = threesomes_list[i];
	return (0);
}

void	display_last_threesome(t_threesome last_threesome,
		t_dict_value *dict_values, int i)
{
	if (i != 0 && !is_empty_threesome(last_threesome))
		ft_putstr(", ");
	if (is_empty_threesome(last_threesome) && i == 0)
		print_threesome_values(last_threesome, dict_values);
	else if (!is_empty_threesome(last_threesome))
		print_threesome_values(last_threesome, dict_values);
}

// Displays all threesomes (or not if values = 000)
// Then display the last one
// If the last one is empty:
//			- If it's the only one : print 0
//			- If not, don't print
void	display_number(t_threesome *threesomes_list, t_dict_value *dict_values)
{
	int				i;
	char			*current_multiple;
	char			*current_data;
	t_threesome		current_threesome;

	i = -1;
	if (is_no_good(threesomes_list, dict_values))
		return (ft_putstr("Error\n"));
	while (threesomes_list[++i].index != 0)
	{
		current_threesome = threesomes_list[i];
		current_multiple = get_multiple(current_threesome.index);
		if (i != 0 && !is_empty_threesome(current_threesome))
			ft_putstr(", ");
		if (!is_empty_threesome(current_threesome))
			print_threesome_values(current_threesome, dict_values);
		current_data = get_associated_data(current_multiple, dict_values);
		if (!is_empty_threesome(current_threesome))
			ft_putstr(current_data);
		free(current_data);
		free(current_multiple);
	}
	display_last_threesome(threesomes_list[i], dict_values, i);
	ft_putstr("\n");
}
