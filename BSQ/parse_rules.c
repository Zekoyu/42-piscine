#include "helper.h"

int	parse_rules(char *file, t_chars_rules *rules)
{
	char			*first_line;
	int				first_line_size;

	first_line_size = get_first_line_size(file);
	if (first_line_size < 4)
		return (0);
	first_line = get_first_line(file, first_line_size);
	if (first_line == NULL)
		return (0);
	if (!parse_line(first_line, first_line_size, rules))
	{
		free(first_line);
		return (0);
	}
	free(first_line);
	return (1);
}

// ln = line
int	parse_line(char *ln, int line_length, t_chars_rules *rules)
{
	int	i;

	i = line_length - 1;
	if (ln[i] == ln[i - 1] || ln[i] == ln[i - 2] || ln[i - 1] == ln[i - 2])
		return (print_error());
	rules->full = ln[i--];
	rules->obstacle = ln[i--];
	rules->empty = ln[i--];
	rules->lines_count = find_num(ln, i + 1);
	return (1);
}

char	*get_first_line(char *file, int length)
{
	int		fd;
	int		head_pos;
	int		curr_char;
	char	buff[1];
	char	*first_line;

	first_line = malloc (sizeof (char) * (length + 1));
	curr_char = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error_free_ptr(first_line));
	head_pos = read(fd, buff, 1);
	while (head_pos > 0 && curr_char < length)
	{
		first_line[curr_char++] = *buff;
		head_pos = read(fd, buff, 1);
	}
	close(fd);
	if (head_pos == -1)
		return (print_error_free_ptr(first_line));
	first_line[curr_char] = '\0';
	return (first_line);
}

int	get_first_line_size(char *file)
{
	char			buff[1];
	int				fd;
	int				head_pos;
	int				first_line_size;

	fd = open(file, O_RDONLY);
	first_line_size = 0;
	if (fd == -1)
		return (print_error());
	head_pos = read(fd, buff, 1);
	while (head_pos > 0)
	{
		if (*buff == '\n')
			break ;
		first_line_size++;
		head_pos = read(fd, buff, 1);
	}
	if (head_pos == -1 || first_line_size < 4)
	{
		close(fd);
		return (print_error());
	}
	close(fd);
	return (first_line_size);
}
