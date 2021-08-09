#include "helper.h"

void	print_map(t_char_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			write(1, &(map->matrix[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
