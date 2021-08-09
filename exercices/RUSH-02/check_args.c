#include <fcntl.h>
#include <unistd.h>

#include "olivia.h"

int	check_args_count(int argc)
{
	if (argc < 2 || argc > 3)
		return (0);
	return (1);
}

// argc = count + 1 to add the executable name
int	display_from_stdin(int *argc, char ***argv)
{
	char	**args_values;
	int		args_count;

	args_count = 0;
	args_values = get_args_from_stdin();
	if (args_values == NULL)
		return (0);
	while (args_values[args_count] != 0)
		args_count++;
	*argv = args_values;
	*argc = args_count;
	return (1);
}

int	check_args_validity(int argc, char **argv)
{
	int	is_num;
	int	fd;

	is_num = 1;
	if (argc == 2)
	{
		is_num = is_number_str(argv[1]);
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (0);
		close(fd);
		is_num = is_number_str(argv[2]);
	}
	if (is_num == 0)
		return (0);
	return (1);
}

int	check_args(int *argc, char ***argv)
{
	if (*argc == 1)
	{
		if (display_from_stdin(argc, argv) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	if (!check_args_count(*argc))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!check_args_validity(*argc, *argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
