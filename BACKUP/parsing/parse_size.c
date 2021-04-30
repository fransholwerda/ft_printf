/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:35:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 16:35:14 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse_size(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		tags->size = 1;
		return (i + 2);
	}
	else if (str[i] == 'l')
		tags->size = 2;
	else if (str[i] == 'h' && str[i + 1] == 'h')
	{
		tags->size = 3;
		return (i + 2);
	}
	else if (str[i] == 'h')
		tags->size = 4;
	return (i + 1);
}
