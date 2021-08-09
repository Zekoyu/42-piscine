/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:45:24 by oronda            #+#    #+#             */
/*   Updated: 2021/07/28 10:04:36 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	fill_with_chars(t_map_data *map_data, t_chars_rules *rules,
											 t_char_map *char_map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			char_map->matrix[y][x]
				= convert_to_char_rules(map_data->matrix[y][x], rules);
			x++;
		}
		y++;
	}
}

int	init_char_map(t_map_data *map_data,
					t_char_map *char_map, t_chars_rules *rules)
{
	int	y;

	y = 0;
	char_map->matrix = malloc(sizeof(char *) * map_data->height);
	if (char_map->matrix == NULL)
		return (print_error());
	while (y < map_data->height)
	{
		(char_map->matrix)[y] = malloc(sizeof(char) * map_data->width);
		if (char_map->matrix[y] == NULL)
			return (print_error_free(char_map->matrix));
		y++;
	}
	char_map->height = map_data->height;
	char_map->width = map_data->width;
	init_char_map_to_null(char_map);
	fill_with_chars(map_data, rules, char_map);
	return (1);
}

char	convert_to_char_rules(int nb, t_chars_rules *rules)
{
	char	result;

	if (nb == 0)
		result = rules->obstacle;
	if (nb > 0)
		result = rules->empty;
	return (result);
}
