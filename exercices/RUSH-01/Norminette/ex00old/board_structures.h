#ifndef __BOARDSTRUCTURES_H__
#define __BOARDSTRUCTURES_H__

typedef struct s_skyscraper	t_skyscraper;
struct	s_skyscraper
{
	int	height;
	int	*possibilities;
	int	fixed;
};

typedef struct s_clues_list t_clues_list;
struct s_clues_list
{
	int	*top;
	int	*bottom;
	int	*left;
	int	*right;
};

typedef struct s_viewpoints t_viewpoints;
struct s_viewpoints
{
	int *top;
	int *bottom;
	int *left;
	int *right;
};

typedef struct s_board t_board;
struct s_board
{
	t_viewpoints 	viewpoints;
	t_skyscraper 	**board;
	int				size;
};

#endif