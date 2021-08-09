#include <unistd.h>

#include "ft_atoi.h"
#include "do_op_functions.h"
#include "put_things.h"

typedef struct s_mafs_functions
{
	void		(*do_mafs)(int, int);
	char		type;
}	t_mafs_function;

void	init_tab(t_mafs_function *mafs_tab)
{
	mafs_tab[0].type = '+';
	mafs_tab[0].do_mafs = &add;
	mafs_tab[1].type = '-';
	mafs_tab[1].do_mafs = &substract;
	mafs_tab[2].type = '/';
	mafs_tab[2].do_mafs = &divide;
	mafs_tab[3].type = '*';
	mafs_tab[3].do_mafs = &multiply;
	mafs_tab[4].type = '%';
	mafs_tab[4].do_mafs = &modulo;
}

void	set_numbers(char **argv, int *x, int *y)
{
	t_atoi_res	x_ato;
	t_atoi_res	y_ato;

	x_ato = ft_atoi(argv[1]);
	y_ato = ft_atoi(argv[3]);
	if (x_ato.num == -1)
		x_ato.num = 0;
	if (y_ato.num == -1)
		y_ato.num = 0;
	*x = (int)(x_ato.num * x_ato.sign);
	*y = (int)(y_ato.num * y_ato.sign);
}

int	main(int argc, char **argv)
{
	int				i;
	int				x;
	int				y;
	char			sign;
	t_mafs_function	mafs_tab[5];

	init_tab(mafs_tab);
	if (argc != 4)
		return (0);
	sign = argv[2][0];
	set_numbers(argv, &x, &y);
	i = -1;
	while (++i < 5)
	{
		if (sign == mafs_tab[i].type && argv[2][1] == '\0')
		{
			mafs_tab[i].do_mafs(x, y);
			return (0);
		}
	}
	write(1, "0\n", 2);
	return (0);
}
