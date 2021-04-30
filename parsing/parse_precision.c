/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:35:32 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/30 14:27:20 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_precision(const char *str, t_tags *tags)
{
	while (str[tags->pos] == '.' || str[tags->pos] == '*')
	{
		tags->pos++;
		if (str[tags->pos] == '*')
		{
			tags->precision_star++;
			tags->pos++;
		}
		else
		{
			tags->precision = ft_atoi(&str[tags->pos]);
			tags->pos += count_digits(str, tags->pos);
		}
	}
}
