#include "../ex03/ft_point.h"
#include <stdio.h>
void	set_point(t_point *point)
{
	point->x = 42;
	point ->y = 21;
}

int main()
{
	printf("================= EX 03 =================\n");

	t_point	point;

	printf("Point before (?, ?) : %d %d\n", point.x, point.y);
	set_point(&point);
	printf("Point after (42, 21) : %d %d\n", point.x, point.y);
	return (0);

}
