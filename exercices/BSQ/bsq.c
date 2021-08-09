/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:30:00 by oronda            #+#    #+#             */
/*   Updated: 2021/07/28 15:27:46 by mframbou         ###   ########.fr       */
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

#include "helper.h"

int	white_magic(char *file)
{
	int		fd;
	int		head_pos;
	char	*buff[42000];

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (print_error());
	head_pos = read(0, buff, 42000);
	while (head_pos > 0)
	{
		write(fd, buff, head_pos);
		head_pos = read(0, buff, 42000);
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
