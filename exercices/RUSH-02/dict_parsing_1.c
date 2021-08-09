#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "olivia.h"
#define DICT_ERROR "Dict Error\n"

int	count_lines(char *buffer)
{
	char	**split_values;
	int		i;
	int		lines_count;

	split_values = ft_split(buffer, "\n");
	i = 0;
	lines_count = 0;
	while (split_values[i] != 0)
	{
		lines_count++;
		free(split_values[i]);
		i++;
	}
	free(split_values);
	return (lines_count);
}

int	count_non_empty_lines(char *file)
{
	int		fd;
	int		head_pos;
	char	buff[FT_BUFF_SIZE + 1];
	int		lines_count;

	fd = open (file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(DICT_ERROR);
		return (-1);
	}
	lines_count = 0;
	head_pos = read(fd, buff, FT_BUFF_SIZE);
	while (head_pos > 0)
	{
		buff[head_pos] = '\0';
		lines_count += count_lines(buff);
		head_pos = read(fd, buff, FT_BUFF_SIZE);
	}
	if (head_pos == -1)
	{
		ft_putstr(DICT_ERROR);
		return (-1);
	}
	return (lines_count);
}

void	add_lines(char *buff, char **lines, int *index)
{
	char	**split_values;
	int		i;
	int		lines_count;

	split_values = ft_split(buff, "\n");
	i = 0;
	lines_count = 0;
	while (split_values[i] != 0)
	{
		lines[*index] = split_values[i];
		(*index)++;
		i++;
	}
	free(split_values);
}

void	get_lines(char *file, char **lines)
{
	int		fd;
	int		head_pos;
	char	buff[FT_BUFF_SIZE + 1];
	int		index;

	index = 0;
	fd = open (file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(DICT_ERROR);
		return ;
	}
	head_pos = read(fd, buff, FT_BUFF_SIZE);
	while (head_pos > 0)
	{
		buff[head_pos] = '\0';
		add_lines(buff, lines, &index);
		head_pos = read(fd, buff, FT_BUFF_SIZE);
	}
	if (head_pos == -1)
	{
		ft_putstr(DICT_ERROR);
		return ;
	}
}

// Free lines after parsing
t_dict_value	*parse_dict(char *file)
{
	t_dict_value	*dict_values;
	char			**lines;
	int				lines_count;

	lines_count = count_non_empty_lines(file);
	lines = malloc (sizeof (char *) * lines_count);
	get_lines(file, lines);
	dict_values = parse_lines(lines, lines_count);
	lines_count--;
	while (lines_count >= 0)
	{
		free(lines[lines_count]);
		lines_count--;
	}
	free(lines);
	return (dict_values);
}
