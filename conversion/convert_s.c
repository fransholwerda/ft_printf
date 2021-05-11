/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 12:27:55 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/06 17:21:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	convert_s(t_tags *tags, va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if ((tags->width - ft_strlen(str)) > 0)
	{
		if (tags->flag_minus == 1)
		{
			tags->printed += ft_putstr(str, tags->precision);
			tags->printed += print_blank(tags->width - ft_strlen(str), tags);
		}
		else
		{
			tags->printed += print_blank(tags->width - ft_strlen(str), tags);
			//printf("\n\nprinted: %d\n\n", tags->printed);
			tags->printed += ft_putstr(str, tags->precision);
			//printf("\n\nprinted: %d\n\n", tags->printed);
		}
	}
	else
		tags->printed += ft_putstr(str, tags->precision);
	tags->pos++;
}
