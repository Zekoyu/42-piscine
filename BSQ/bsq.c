/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:30:00 by oronda            #+#    #+#             */
/*   Updated: 2021/07/28 09:49:01 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	white_magic(char *file)
{
	int		fd;
	int		head_pos;
	char	*buff[42];

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (print_error());
	head_pos = read(0, buff, 42);
	while (head_pos > 0)
	{
		write(fd, buff, head_pos);
		head_pos = read(0, buff, 42);
	}
	if (head_pos == -1)
		return (print_error());
	close(fd);
	return (1);
}

void	black_magic(char *file)
{
	t_map_data		map_data;
	t_char_map		char_map;
	t_chars_rules	rules;
	t_point			bsq_start_point;

	bsq_start_point.value = 0;
	bsq_start_point.x = 0;
	bsq_start_point.y = 0;
	if (!parse_rules(file, &rules))
		return ;
	if (!check_map(file, &map_data, &rules))
		return ;
	if (!parse_map(file, &map_data, &rules))
		return ;
	find_bsq(&map_data, &bsq_start_point);
	init_char_map(&map_data, &char_map, &rules);
	if (bsq_start_point.value == 0)
	{
		print_map(&char_map);
		return ;
	}
	fill_bsq(&char_map, &rules, &bsq_start_point);
	print_map(&char_map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (!white_magic("pouic.pouet"))
			return (0);
		black_magic("pouic.pouet");
		i = open("pouic.pouet", O_RDWR | O_TRUNC, S_IRWXU);
		close(i);
		return (0);
	}
	else if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			black_magic(argv[i]);
			if (i != argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
