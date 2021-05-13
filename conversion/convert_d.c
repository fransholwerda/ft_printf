/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:41:51 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 13:15:27 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	get_width(t_tags *tags, int d, int digits)
{
	int	width;

	if (tags->precision > digits)
		width = tags->width - tags->precision;
	else if (tags->precision_true && !tags->precision && !d)
		width = tags->width;
	else
		width = tags->width - digits;
	if (d < 0)
		width -= 1;
	return (width);
}

static void	print_d(t_tags *tags, int d, int digits, int width)
{
	if (tags->flag_minus)
	{
		if (d < 0)
			tags->printed += ft_putchar('-');
		tags->printed += print_pzero(tags->precision - digits);
		ft_putint(d, tags);
		tags->printed += print_blank(width, tags);
	}
	else
	{
		if (d < 0 && tags->flag_zero)
			tags->printed += ft_putchar('-');
		tags->printed += print_blank(width, tags);
		if (d < 0 && !tags->flag_zero)
			tags->printed += ft_putchar('-');
		tags->printed += print_pzero(tags->precision - digits);
		ft_putint(d, tags);
	}
}

void	convert_d(t_tags *tags, va_list *arg)
{
	int	d;
	int	digits;
	int	width;

	d = va_arg(*arg, int);
	digits = int_digits(d);
	width = get_width(tags, d, digits);
	if (tags->precision_true && tags->flag_zero)
		tags->flag_zero = 0;
	print_d(tags, d, digits, width);
	tags->pos++;
}
