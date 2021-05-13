/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:36:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 16:13:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_width(const char *str, va_list *arg, t_tags *tags)
{
	while (ft_isdigit(str[tags->pos]) || str[tags->pos] == '*')
	{
		if (str[tags->pos] == '*')
		{
			tags->width = va_arg(*arg, int);
			if (tags->width < 0)
			{
				tags->width *= -1;
				tags->flag_minus++;
				tags->flag_zero = 0;
			}
			tags->pos++;
		}
		else
		{
			tags->width = ft_atoi(&str[tags->pos]);
			tags->pos += count_skip(str, tags->pos);
		}
	}
}
