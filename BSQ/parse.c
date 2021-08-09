#include "helper.h"

int	parse_map(char *file, t_map_data *map, t_chars_rules *rules)
{
	int	fd;

	fd = move_to_first_line(file);
	if (fd == 0)
		return (0);
	if (!fill_data(fd, map, *rules))
		return (0);
	return (1);
}

int	fill_data(int fd, t_map_data *map, t_chars_rules rules)
{
	char	buff[1];
	int		x;
	int		y;

	y = 0;
	map->matrix = malloc(sizeof(t_ushort *) * map->height);
	if (map->matrix == NULL)
		return (print_error());
	while (y < map->height)
		(map->matrix)[y++] = malloc(sizeof(t_ushort) * map->width);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			read(fd, buff, 1);
			if (*buff == '\n')
				continue ;
			(map->matrix)[y][x] = convert_to_int(rules, *buff);
			x++;
		}	
		y++;
	}
	return (1);
}

int	convert_to_int(t_chars_rules rules, char c)
{
	if (c == rules.empty)
		return (1);
	if (c == rules.obstacle)
		return (0);
	return (-1);
}

void	set_map_datas(t_map_data *map_data, int width, int height)
{
	map_data->width = width;
	map_data->height = height;
}
