/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mframbou <mframbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:30:14 by oronda            #+#    #+#             */
/*   Updated: 2021/07/28 15:25:25 by mframbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

#define MAP_ERROR_MSG "map error\n"

int	print_error(void)
{
	put_str_error(MAP_ERROR_MSG);
	return (0);
}

int	print_error_free(void *to_free)
{
	free(to_free);
	put_str_error(MAP_ERROR_MSG);
	return (0);
}

void	*print_error_free_ptr(void *to_free)
{
	free(to_free);
	put_str_error(MAP_ERROR_MSG);
	return (NULL);
}

void	put_str_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}
