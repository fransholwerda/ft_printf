/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:41:51 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 02:14:09 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	convert_d(t_tags *tags, va_list *arg)
{
	int	d;
	int	digits;
	int	width;

	d = va_arg(*arg, int);
	digits = count_digits(d);
	if (tags->precision > digits)
		width = tags->width - tags->precision;
	else if (tags->precision_true && !tags->precision && !d)
		width = tags->width;
	else
		width = tags->width - digits;
	if (tags->flag_minus)
	{
		tags->printed += print_pzero(tags->precision - digits);
		ft_putnbr(d, tags);
		tags->printed += print_blank(width, tags);
	}
	else
	{
		tags->printed += print_blank(width, tags);
		tags->printed += print_pzero(tags->precision - digits);
		ft_putnbr(d, tags);
	}
	tags->pos++;
}
