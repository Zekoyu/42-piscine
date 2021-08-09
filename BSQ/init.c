#include "helper.h"

void	init_char_map_to_null(t_char_map *char_map)
{
	int	x;
	int	y;

	y = 0;
	while (y < char_map->height)
	{
		x = 0;
		while (x < char_map->width)
		{
			char_map->matrix[y][x] = 127;
			x++;
		}
		y++;
	}
}
