/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 15:42:06 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 15:57:24 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	get_width(t_tags *tags, u_int64_t u, int digits)
{
	int	width;

	if (tags->precision > digits)
		width = tags->width - tags->precision;
	else if (tags->precision_true && !tags->precision && !u)
		width = tags->width;
	else
		width = tags->width - digits;
	width -= 2;
	return (width);
}

void	convert_p(t_tags *tags, va_list *arg)
{
	u_int64_t	u;
	int			digits;
	int			width;

	u = va_arg(*arg, u_int64_t);
	digits = pointer_digits(u);
	width = get_width(tags, u, digits);
	if (tags->precision_true && tags->flag_zero)
		tags->flag_zero = 0;
	if (tags->flag_minus)
	{
		tags->printed += print_pzero(tags->precision - digits);
		tags->printed += write(1, "0x", 2);
		ft_putpointer(u, tags);
		tags->printed += print_blank(width, tags);
	}
	else
	{
		tags->printed += print_blank(width, tags);
		tags->printed += print_pzero(tags->precision - digits);
		tags->printed += write(1, "0x", 2);
		ft_putpointer(u, tags);
	}
	tags->pos++;
}
