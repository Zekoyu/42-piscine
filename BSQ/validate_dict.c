#include "helper.h"

int	check_map(char *file, t_map_data *map_data, t_chars_rules *rules)
{
	int	fd;

	fd = move_to_first_line(file);
	if (fd == 0)
		return (0);
	if (!count_lines(fd, map_data, rules))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	count_lines(int fd, t_map_data *map_data, t_chars_rules *rules)
{
	int		x;
	int		numbers_of_lines;
	char	buffer[1];
	int		line_length;

	x = 0;
	numbers_of_lines = 0;
	while (read(fd, buffer, 1))
	{
		if (*buffer == '\n')
		{
			if (!set_check_line_length(numbers_of_lines, x, &line_length))
				return (0);
			x = 0;
			numbers_of_lines++;
			continue ;
		}
		if (!is_valid_char(*rules, *buffer))
			return (print_error());
		x++;
	}
	if (*buffer != '\n')
		return (print_error());
	set_map_datas(map_data, line_length, numbers_of_lines);
	return (1);
}

int	set_check_line_length(int number_of_lines, int x, int *line_length)
{
	if (number_of_lines == 0)
		*line_length = x;
	else if (*line_length != x)
		return (print_error());
	return (1);
}

int	is_valid_char(t_chars_rules rules, char c)
{
	if (rules.empty == c)
		return (1);
	else if (rules.obstacle == c)
		return (1);
	else
		return (0);
}

int	move_to_first_line(char *file)
{
	int		fd;
	int		head_pos;
	char	buff[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error());
	head_pos = read(fd, buff, 1);
	while (head_pos > 0)
	{
		if (*buff == '\n')
			break ;
		head_pos = read(fd, buff, 1);
	}
	if (head_pos == -1)
	{
		close(fd);
		return (print_error());
	}
	return (fd);
}
