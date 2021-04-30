/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:36:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/30 14:24:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_width(const char *str, t_tags *tags)
{
	while (ft_isdigit(str[tags->pos]) || str[tags->pos] == '*')
	{
		if (str[tags->pos] == '*')
		{
			tags->width_star++;
			tags->pos++;
		}
		else
		{
			tags->width = ft_atoi(&str[tags->pos]);
			tags->pos += count_digits(str, tags->pos);
		}
	}
}
