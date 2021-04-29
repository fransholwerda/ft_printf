/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 16:43:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/29 14:35:54 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	convert_c(long int i, t_tags *tags, va_list arg)
{
	int		width;

	width = 0;
	if (tags->width > 0)
		width = tags->width;
	else if (tags->width_star == 1)
		width = va_arg(arg, int);
	if (width > 0)
	{
		if (tags->flag_minus == 1)
		{
			ft_putchar_fd(va_arg(arg, int), 1);
			print_blank(width - 1);
		}
		else
		{
			print_blank(width - 1);
			ft_putchar_fd(va_arg(arg, int), 1);
		}
	}
	else
		ft_putchar_fd(va_arg(arg, int), 1);
	return (i + 1);
}
