/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:26:45 by mframbou          #+#    #+#             */
/*   Updated: 2021/07/28 15:49:53 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	print_map(t_char_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		write(1, map->matrix[y], map->width);
		write(1, "\n", 1);
		y++;
	}
}
