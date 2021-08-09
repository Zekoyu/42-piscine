/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 00:00:00 by oronda            #+#    #+#             */
/*   Updated: 2021/07/28 15:51:40 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//hhhhhhhdNNNNNmdmdhhyyyyyyysssssooooo++++//////:::::---/smmmddhhhhhhhhhhhhhhhhh
//hhhhhhdNNNmNmdhhyyyyyyysssssssoooo+++++/////:::::------:sdmmmdhhhhhhhhhhhhhhhh
//hhhhhhmNmmmmdyyyyyyyyyysssssssssoo+++++/////::::----.---/hdmmddhhhhhhhhhhhhhhh
//hhhhhmmmmmmdyyyyyyyyyyysssssssssooo+++///////:::---...---sdmmmdhhhhhhhhhhhhhhh
//hhhhdmmmmmdhyyyyyyyyyyyssssssssoooo++++//////:::---....../yhdmddhhhhhhhhhhhhhh
//hhhhmddmmmdhyyyyyyyyyyyssssooooooo++++++//////::---.......+ssdddhhhhhhhhhhhhhh
//hhhdNddmmmdhysyyyyyysssssoo++++++++++++++////:--.......``.:+ohdhhhhhhhhhhhhhhh
//hhhmmdddmmdyssssyssssssoooo++++++++++++++//:::--..........-/+yhyyhhhhhhhhhhhhh
//hhdmmdddmmdhssssssssssssoooooooo+++++++++++//:::--........-//soyohhhhhhhhhhhhh
//hhdmmmddmmmysssssssssyyyyyyyyssssoooo++oooooooo+o++:-:--..-::o+soshhhhhhhhhhhh
//hhdmmmdmmNdsssssyyyyhhhhddddddhhyyssoo+++++oosssssoo+/--...:+++oosdhhhhhhhhhhh
//hhdmNmmmNmyssssyhhhhhhhhhddmmmmmdhsso+/-.:+syyhhyysso/:--..-osoyyshhhhhhhhhhhh
//hhhdNNmmmhssssyhhhhhhhddddmNNNNmmhysoo/-.:oydmmNNmdyss+/:-..:syydshhhhhhhhhhhh
//hhhdNNmmmysssyhhddmmmNMMNNmNNNmmdhysso/---:oddmmNNmysoyo:-...oyhh+hhhhhhhhhhhh
//hhhmNNmmmyssyhhddmdddmmmmmmmmmmdhhyssoo:.-:/+syyys+/-.-::-.-.+yhs/yhhhhhhhhhhh
//hhhmdmmmdyssyyhhhyhhhhddddmdddhhyyyyso+:..-::/+oooo//:---....-syo+ohhhhhhhhhhh
//hhdddddmdyssyyyyyyyyhhhhhhhhhyyyyyyyys+:-....-:://////:-......ohyo+hhhhhhhhhhh
//hhdhyyhmdyssssyyysssyyyyyyyyyyyyyyyyyso:--...--::::::--.......oy:s/hhhhhhhhhhh
//hhdhyhmmmysssssssssssssyyyyyyyyyyyyysso/:-..-:::-----...``....sh:/:dhhhhhhhhhh
//hhdhdmmNmhsssssssssssssyyyyhhhhhhyyyyso+:.--:+o+/--....```...-hhs::dhhhhhhhhhh
//hhddmmmhmdysssssssssssyyyyhddddhhyhyyys+-.:--+sys+:--.......-/hhy//dhhhhhhhhhh
//hhdhmmmhdmdyssysssyyyyyyyhdddddhdmNmdddh++hy/:+ssso/:-......:yhyo//hhhhhhhhhhh
//hhhhhhhdddmhyysyyyyyyyyyyhddhhhdmmmdddds+/++/::/+++/:--....-+o:.//:hhhhhhhhhhh
//hhhdysshhddhyyyyyyyyyyyhhhhhhhdddddddhhys+++/////:::---...--o-----shhhhhhhhhhh
//hhhhdhhhhhdhhyyyyyyyyyyyyhhhdddddddhhdmdys++++++++/-----.--:o+/:/shhhhhhhhhhhh
//hhhhhhhdddhhhyyyyyyyyyyhhhddddddddhyyddhso+++//++++---...-:::osyyhhhhhhhhhhhhh
//hhhhhhhhhhhhhyyyyyyyyyyhdddddddddddhhhyssso++++ooo+:-.---:::+hhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhhyyyyyyyyhhhhhddmmmmmmmmmmhhhhyssyhhhys/----:::/yhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhdhhhyyyyyhhhhhdmmmmdmmmmddhhys+/:/:-/ss+--:::::ohhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhdhhyyyyyyyhhhhhhhhhhdddhhhyys+/------/o/:-:::/:yhhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhdhhhyyhhhhhhhhhhyhhhhhddddhyyo//:----:::::-:/++hhhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhhhhddhhhhhhhhhhhhhhhhhhdhdhyys+/::--::::---:+/yhhhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhhdhhddhhhhhhhhhhhhhhhhdhdhhyyo+//::--:----://:NNdhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhhhhhhdddhhhhhhhyyhhhhhhhhhhyso+//::--:::::+/:-mMMNmhhhhhhhhhhhhhhh
//hhhhhhhhhhhhdmyyhhddddhhhhhhyyyyyhhhhyyso+//::::::::/+/::-hMMMMNmdhhhhhhhhhhhh
//hhhhhhhhhddmNNyyhhddmmdddhddhhhhhhhhyyyys+++////////+/:---yMMMMMMNNNmmddddhhhh
//hhddmmmNNMMMMMyhhhddddmmdddddddddddhhyyyssoo++///+o+/:----sMMMMMMMMMMMMMMMNNmm
//NNMMMMMMMMMMMMmhhhhhdddmmmmmmmmddddddhhhyyysooo+o+/::-----yMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMdhhhhhhddddmmmmmmmmmmmddhhhhyysso/:::-----/dMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMNdhhhhhdddddddmmmmmmmmmmddhyso+/:::::::-:/smMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMNddhhhhdddddddddmmddddhhys+++//:::::--:/ohNMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMNmdhhhhddddddddddddddhhso+/////:::-::/oydNMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMNmddhhhhdddddmmmmddddhyoo++///::::/+oydmMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMNmmdhhhhhhdddddmmmmdhhyoo+//::::/+syhmNMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMNNmdhhhhhhhhddddddhhyso++//::/+ooyhmNNMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMNNmddhhhhhhhhhhhhyysso+++/++oosyhdmNNMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMNNNmdddhhhhhhhhhyyyssoooooosssyhmmNNNNMMMMMMMMMMMNNMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMNNNmmddhhhhhhyyyyssssssssyyyhdmmNNNNNNNNMMMMMMMMMNMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMNNNNmmmddhhhhyyyyyyyyyyyyhhhddmmmNNNNNNNMMMMMMMMMNMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMNNNNmmmddhhhhhhhhhhhhhhhhdddmmmmmmmmNNNMMMMMMMMMNMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMNNNNmmmdhhhhhhhhhhhhhhhhhhddmmmmmmmmmNMMMMMMMMMNNMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMmmmmmmdhyyyyyhhhhhhhhhhhhhddmmmmmmmNNMMMMMMMMMNNMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMmdddddhysssyyyyhhhhhhhhhhdddmmmmmNNMMMMMMMMMMNNMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMNdhdhhhysssyyyyyyhyyhhhhdddddmmmmNMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMNdhhhhyyyyyyyyhyyyyhhhhdddddmmmNNMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMNmhhhyhyhhhhhhyyyyhhhhdddddmmNMMMMMMNMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmhhhhhddhhhhhhhhhhddddddmmmNMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmddhhdddddddhhhhddddddmmmNMMMMMMMMMMNMMMMMMMMMM

//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMNNNNNNmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhhyhhmNNNNNmdmdddmmNMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMmdhhhhddmNNNNNNMMMMNNNNNmddmNMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMNmdmmmmmmmmmmNNNNNNNNNNNNNNNmmdhhmMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMmhdmmmmmddddhhddmmmNNmmmmmmmmmmmmmdhmMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMmhdmmmdhhhyyyyysssssoooossyhdddhdmdmNmdhmMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMNddmdhhyyyyyysssssoooo+++///////oyhhhhhddhydMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMNmmdhyyyyyyysssssoooo++++////:::---:+ss+ooydhhNMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMNmddhhyyyyyyysssssoooo++++////:::-----..:::+osyysNMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMmmdhhyyyyyyyyssssssooo+++////::---.......-::::+syyNMMMMMMMMMMMM
//MMMMMMMMMMMMMMmmddhyyyyyyyyyysssssoo++++////::---......``.-:::/sydMMMMMMMMMMMM
//MMMMMMMMMMMMMmmmdhyyyyyyyysysssssooo+++////:::--.....`````.:+:-+oomMMMMMMMMMMM
//MMMMMMMMMMMMNmmddhyyyyyyyysssssssooo++++///::---......`````-://:/+yMMMMMMMMMMM
//MMMMMMMMMMMMNNmdhyyyyyyyyyyyyssssoooo++++///::--.....`````..::/:///mMMMMMMMMMM
//MMMMMMMMMMMMmNmdyyyyyhhddmmmmmddhysso++++++oso+/:-..```   `.-/+////sMMMMMMMMMM
//MMMMMMMMMMMMNNNmhhhddddddmmmmmmmdhyss+//+oyhddhhs+/-.`     .-:+o///sMMMMMMMMMM
//MMMMMMMMMMMMNdmMNmhhdddddddmmNNNmmhys/::/oyddddhyo/:-.`    .-+os/::yMMMMMMMMMM
//MMMMMMMMMMMMMNNNmmhdddmmmmNNNNNNNNNNmdddsshdmmdhys+/:-/+so/--/os+//MMMMMMMMMMM
//MMMMMMMMMMMMMNNmhmyyyhmmmNMMNNmmmmNdhhNN/ohmmmmmhyo+:.``/NNs/+oo+:yMMMMMMMMMMM
//MMMMMMMMMMMmdmmdyyssyyhhddmmmmmdmNhs+-om/oyddmNNdyhso/-.:h/oyo+o+/NMMMMMMMMMMM
//MMMMMMMMMMMmyhddhsssyyyyyhhdddhdNdyo/..s+:oyyyyso+:-.`  //`/dmhs/sMMMMMMMMMMMM
//MMMMMMMMMMNmyhhyhhhyyyyyyyyhhdmNdys+:-.:d+://////:-.`  `+` -syy+/+sNMMMMMMMMMM
//MMMMMMMMMMNdyhdsosyyhhhhhhdmmmddhys/:-..ss+++/::--.``.-:- `/+//:/shsNMMMMMMMMM
//MMMMMMMMMMNmydmsooosssssyyhhddhhhys+:-..-/soooo+++///:.`  .oo//-.-ooNMMMMMMMMM
//MMMMMMMMMMMmhmmyooooossssyyhhhhmNdho/yyo.-oo+/:-..``     ``yds+-.+yhMMMMMMMMMM
//MMMMMMMMMMMMmdhyooooossssyyyyhhddhh+/oss::+++/:-..``    `-:syys.:oyMMMMMMMMMMM
//MMMMMMMMMMMMNmhsooooosssssssssysssso:-----:///:-..``    -++ooo/-/sNMMMMMMMMMMM
//MMMMMMMMMMMMMMNdsoosssssssssssssssso/---..-::/:--.```   .-./+/::dMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMdyoosssssshhhyyhyyys+/:----:/::--.```  ....--:sNMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMdossssssyhdmmmmmmdhhhysoo+oo/--..``` ``/hdddNMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMsossssssssyhdddhhyso++++++o/-..``````-mMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMdossyyysssssyyyyyyo+/::------..`````:mMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMd+ssysssssssssssso+/::---.....``` `+NMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMhoossysssssssssoo++//:-...``````  /NMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMsosossyysssssssoo++//:-.``````    mMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMoossssssyyyyyyyssso/::-...````    MMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMmoooosssssyyyhhhhhyyo+/--.``````   MMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMhoooossssssssyyyyyso+::.`   ````  `MMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMdsooooossssssssssso++:-.``   ````  `hMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMNyssooooosssssssyysso+/:-.``   ````   .sNMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMNdyssssooooooosssssyyysso+:-.``` ````     `:hMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMmhsoossssoooooooossssssssso+:--`````````     ``+dNMMMMMMMMMMMMMMMMMMM
//MMMMMMMMmoooooossooooooooosssssssso+/:-.````.````     `` odhmNMMMMMMMMMMMMMMMM
//MMMMMMMMMmsooooooooooooooossssssso++/:-.``....```    ```.hmmmmdmNMMMMMMMMMMMMM
//MMMMMMMMMMNhsoooooooooosooossssssso+/:-.`.......``   ``.yNNNNNNmmmNMMMMMMMMMMM
//MMMMMMMMMMMMNysoooooooosssooooosoo++/:-......--..`  ``-sNNNNNNNMNNmNNNNNMMMMMM
//MMMMMMMMMMMMMMNyoooooooossoo++ooo++//:---...-::-..```:hNNNNNNNMNNNMNNNMNNmmmNM
//MMMMMMMMMMMMMMMMNmyoo+++oooo+://++/////:.``.-------:omNNNNNNNNMMNNMMMNMMMMMmmm
//MMMMMMMMMMMMMMMMMMMmho+++ooo+-.-://///+:```.-..-/+ymNNNNNNNMNNMMNNNMMMNMMMMMMN
//MMMMMMMMMMMMMMMMMMMMMNhysso+/-`.-:///+/:.....-:+ymNMMMNNNNMMMNNMNNMMMMNNMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMNh+:...-:/++++/:-..-odNNMMMMNNNMMMMMMNMMNMMMMMNNMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMmhhyyyyyyyyyydmMMNMMMNNNNNNMMMMMMNNMMMMMMMMNMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMNNMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMMMMMMMMM

#ifndef HELPER_H
# define HELPER_H

// Includes
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// Structs / typedefs
typedef unsigned short	t_ushort;
typedef struct s_point
{
	int			x;
	int			y;
	t_ushort	value;
}	t_point;

typedef struct s_chars_rules
{
	char	empty;
	char	obstacle;
	char	full;
	int		lines_count;
}	t_chars_rules;

typedef struct s_map_data
{
	int			width;
	int			height;
	t_ushort	**matrix;
}	t_map_data;

typedef struct s_char_map
{
	int			width;
	int			height;
	char		**matrix;
}	t_char_map;

// Functions

// Parse rules
int			parse_rules(char *file, t_chars_rules *rules);
char		*get_first_line(char *file, int length);
int			get_first_line_size(char *file);
int			parse_line(char *ln, int line_length, t_chars_rules *rules);

// Validate map
int			count_lines(int fd, t_map_data *map_data, t_chars_rules *rules);
int			is_valid_char(t_chars_rules *rules, char c);
int			check_map(char *file, t_map_data *map_data, t_chars_rules *rules);
int			set_check_line_length(int number_of_lines, int x, int *line_length);
int			count_lines_pouet(int fd, int line_length, int *numbers_of_lines,
				t_chars_rules *rules);
// Handle errors
void		put_str_error(char *str);
int			print_error(void);
int			print_error_free(void *to_free);
void		*print_error_free_ptr(void *to_free);

// Str helper
int			find_num(char *str, int length);

// Print map
void		print_map(t_char_map *map);

// Parse 
int			fill_data(int fd, t_map_data *map, t_chars_rules rules);
int			convert_to_int(t_chars_rules rules, char c);
int			parse_map(char *file, t_map_data *map, t_chars_rules *rules);
void		set_map_datas(t_map_data *map_data, int width, int height);
int			move_to_first_line(char *file);

// Parse char
char		convert_to_char_rules(int nb, t_chars_rules *rules);
int			init_char_map(t_map_data *map_data, t_char_map *char_map,
				t_chars_rules *rules);

// Init 
void		init_char_map_to_null(t_char_map *char_map);

// Find & fill BSQ
t_ushort	get_min_value(t_ushort tac, t_ushort sky, t_ushort yoshi);
t_ushort	min_value_nearby(t_ushort **matrix, int row, int col);
void		find_bsq(t_map_data *map_data, t_point *bsq_start_pt);
void		fill_bsq(t_char_map *char_map, t_chars_rules *rules,
				t_point *bsq_start);

#endif