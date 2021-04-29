/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 12:27:55 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/29 13:18:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	convert_s(const char *str, long int i, t_tags *tags, va_list va)
{
	char	*arg;
	char	*print;
	int		width;

	width = 0;
	if (tags->width > 0)
		width = tags->width;
	else if (tags->width_star == 1)
		width = va_arg(va, int);
	arg = va_arg(va, char *);
}
