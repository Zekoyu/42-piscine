/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:14:22 by mframbou          #+#    #+#             */
/*   Updated: 2021/07/28 15:51:56 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			line_length = x;
			numbers_of_lines++;
			break ;
		}
		if (!is_valid_char(rules, *buffer))
			return (print_error());
		x++;
	}
	if (*buffer != '\n')
		return (print_error());
	if (!count_lines_pouet(fd, line_length, &numbers_of_lines, rules))
		return (0);
	set_map_datas(map_data, line_length, numbers_of_lines);
	return (1);
}

int	count_lines_pouet(int fd, int line_length, int *numbers_of_lines,
					  t_chars_rules *rules)
{
	char	*line_buff;
	int		i;

	line_buff = malloc (sizeof (char) * line_length + 1);
	while (read(fd, line_buff, line_length + 1))
	{
		i = 0;
		if (line_buff[line_length] != '\n')
			return (print_error_free(line_buff));
		while (i < line_length)
		{
			if (!is_valid_char(rules, line_buff[i]))
				return (print_error_free(line_buff));
			i++;
		}
		(*numbers_of_lines)++;
	}
	free(line_buff);
	close(fd);
	if (rules->lines_count != *numbers_of_lines)
		return (print_error());
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

int	is_valid_char(t_chars_rules *rules, char c)
{
	if (rules->empty == c)
		return (1);
	else if (rules->obstacle == c)
		return (1);
	else
		return (0);
}
