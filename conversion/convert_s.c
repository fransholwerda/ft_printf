/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 12:27:55 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/12 13:25:08 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	convert_s(t_tags *tags, va_list *arg)
{
	char	*str;
	int		width;

	str = va_arg(*arg, char *);
	if (str == NULL)
		str = "(null)";
	if (tags->precision_true && tags->precision < ft_strlen(str))
		width = tags->width - tags->precision;
	else
		width = tags->width - ft_strlen(str);
	if (tags->flag_minus)
	{
		tags->printed += ft_putstr(str, tags);
		tags->printed += print_blank(width, tags);
	}
	else
	{
		tags->printed += print_blank(width, tags);
		tags->printed += ft_putstr(str, tags);
	}
	tags->pos++;
}
