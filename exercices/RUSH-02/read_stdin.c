#include <fcntl.h>
#include <unistd.h>

#include "olivia.h"

#define READ_STDIN_BUFF_SIZE 16000

// Start from 2, so that I can add a fake arg
// To get the right count
// Then work with buffer + 3 because of the terminating char

#include <stdio.h>

char	**get_args_from_stdin(void)
{
	int		head_pos;
	int		args_count;
	char	buff[READ_STDIN_BUFF_SIZE + 1];
	char	**argv;

	argv = NULL;
	head_pos = read(1, buff + 2, READ_STDIN_BUFF_SIZE - 2);
	if (head_pos == -1)
	{
		argv = NULL;
		return (argv);
	}
	buff[0] = 'A';
	buff[1] = ' ';
	buff[head_pos + 3] = '\0';
	printf("%s | %d\n",buff, head_pos - 1 + 3);
	if (head_pos >= 1 && buff[head_pos - 1 + 3] == '\n')
		buff[head_pos - 1] = '\0';
	argv = ft_split(buff, " ");
	args_count = 0;
	while (argv[args_count] != 0)
		args_count++;
	return (argv);
}
