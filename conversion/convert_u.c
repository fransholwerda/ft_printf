/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 13:01:11 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 13:19:54 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	get_width(t_tags *tags, u_int32_t u, int digits)
{
	int	width;

	if (tags->precision > digits)
		width = tags->width - tags->precision;
	else if (tags->precision_true && !tags->precision && !u)
		width = tags->width;
	else
		width = tags->width - digits;
	return (width);
}

void	convert_u(t_tags *tags, va_list *arg)
{
	u_int32_t	u;
	int			digits;
	int			width;

	u = va_arg(*arg, u_int32_t);
	digits = uint_digits(u);
	width = get_width(tags, u, digits);
	if (tags->precision_true && tags->flag_zero)
		tags->flag_zero = 0;
	if (tags->flag_minus)
	{
		tags->printed += print_pzero(tags->precision - digits);
		ft_putuint(u, tags);
		tags->printed += print_blank(width, tags);
	}
	else
	{
		tags->printed += print_blank(width, tags);
		tags->printed += print_pzero(tags->precision - digits);
		ft_putuint(u, tags);
	}
	tags->pos++;
}
