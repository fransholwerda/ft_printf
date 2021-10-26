/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conversion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:34:22 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_conversion(const char *str, va_list *arg, t_tags *tags)
{
	if (str[tags->pos] == 'c')
		convert_c(tags, arg);
	else if (str[tags->pos] == 's')
		convert_s(tags, arg);
	else if (str[tags->pos] == 'p')
		convert_p(tags, arg);
	else if (str[tags->pos] == 'd')
		convert_d(tags, arg);
	else if (str[tags->pos] == 'i')
		convert_d(tags, arg);
	else if (str[tags->pos] == 'u')
		convert_u(tags, arg);
	else if (str[tags->pos] == 'x')
		convert_x(tags, arg, 0);
	else if (str[tags->pos] == 'X')
		convert_x(tags, arg, 1);
	else if (str[tags->pos] == '%')
		convert_percent(tags);
	else
		tags->pos++;
}
