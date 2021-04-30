/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:36:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 16:36:31 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse_flags(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
	if (str[i] == '#')
		tags->flag_hash++;
	else if (str[i] == '0')
		tags->flag_zero++;
	else if (str[i] == '-')
		tags->flag_minus++;
	else if (str[i] == ' ')
		tags->flag_blank++;
	else if (str[i] == '+')
		tags->flag_plus++;
	tags->skip_pos += 1;
	return (i + 1);
}
