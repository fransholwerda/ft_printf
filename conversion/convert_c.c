/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 16:43:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/06 12:20:39 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	convert_c(t_tags *tags, va_list arg)
{
	if (tags->width > 0)
	{
		if (tags->flag_minus == 1)
		{
			tags->printed += ft_putchar_fd(va_arg(arg, int), 1);
			tags->printed += print_blank(tags->width - 1, tags);
		}
		else
		{
			tags->printed += print_blank(tags->width - 1, tags);
			tags->printed += ft_putchar_fd(va_arg(arg, int), 1);
		}
	}
	else
		tags->printed += ft_putchar_fd(va_arg(arg, int), 1);
	tags->pos++;
}
