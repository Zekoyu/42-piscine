#include "olivia.h"
#include <stdlib.h>

// POUIC (ASCII) = 8 079 857 367
// Checks args directly check from stdin, and puts the values
// inside argc and argv
// Dict values are already freed inside the display_number
// And inside parse_dict in case of an error
int	main(int argc, char **argv)
{
	t_threesome		*threesomes_list;
	t_dict_value	*dict_values;

	dict_values = (void *) 0;
	if (check_args(&argc, &argv) == 0)
		return (0);
	if (argc == 2)
	{
		threesomes_list = parse_to_threesomes(argv[1]);
		dict_values = parse_dict("numbers.dict");
	}
	else if (argc == 3)
	{
		threesomes_list = parse_to_threesomes(argv[2]);
		dict_values = parse_dict(argv[1]);
	}
	if (dict_values == (void *) 0)
	{
		ft_putstr("Dict Error\n");
		free(threesomes_list);
		return (0);
	}
	display_number(threesomes_list, dict_values);
	return (0);
}
