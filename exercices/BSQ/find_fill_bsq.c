/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fill_bsq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:24:51 by mframbou          #+#    #+#             */
/*   Updated: 2021/07/28 15:25:24 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

t_ushort	get_min_value(t_ushort tac, t_ushort sky, t_ushort yoshi)
{
	t_ushort	min;

	min = tac;
	if (min > sky)
		min = sky;
	if (min > yoshi)
		min = yoshi;
	return (min);
}

t_ushort	min_value_nearby(t_ushort **matrix, int row, int col)
{
	t_ushort	left;
	t_ushort	top_left;
	t_ushort	top;

	left = matrix[row][col - 1];
	top_left = matrix[row - 1][col - 1];
	top = matrix[row - 1][col];
	return (get_min_value(left, top_left, top));
}

// Skip first row & column, because they don't have values on their top/left
// If current value is 0, continue
// Otherwise, get the smallest between 3 others
// + 1, so that if a square of size 2 is possible
// 1 | 1
// 1 | 1 => square of size 2 possible from this bottom-right corner

void	find_bsq(t_map_data *map_data, t_point *bsq_start_pt)
{
	int			y;
	int			x;
	t_ushort	*current;
	t_ushort	**matrix;

	matrix = map_data->matrix;
	y = 0;
	while (++y < map_data->height)
	{
		x = 0;
		while (++x < map_data->width)
		{
			current = &(matrix[y][x]);
			if (*current == 1)
			{
				*current = min_value_nearby(matrix, y, x) + 1;
				if (*current > bsq_start_pt->value)
				{
					bsq_start_pt->x = x;
					bsq_start_pt->y = y;
					bsq_start_pt->value = *current;
				}
			}
		}
	}
}

void	fill_bsq(t_char_map *char_map, t_chars_rules *rules, t_point *bsq_start)
{
	int			y;
	int			x;

	y = bsq_start->y;
	while (y > (bsq_start->y - bsq_start->value))
	{
		x = bsq_start->x;
		while (x > (bsq_start->x - bsq_start->value))
		{
			char_map->matrix[y][x] = rules->full;
			x--;
		}
		y--;
	}
}
