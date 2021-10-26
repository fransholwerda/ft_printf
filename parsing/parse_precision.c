/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:35:32 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_precision(const char *str, va_list *arg, t_tags *tags)
{
	while (str[tags->pos] == '.')
	{
		tags->precision_true = 1;
		tags->pos++;
		if (str[tags->pos] == '*')
		{
			tags->precision = va_arg(*arg, int);
			if (tags->precision < 0)
				tags->precision_true = 0;
			tags->pos++;
		}
		else
		{
			tags->precision = ft_atoi(&str[tags->pos]);
			tags->pos += count_skip(str, tags->pos);
		}
	}
}
