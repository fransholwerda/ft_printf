/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/30 11:17:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_str(const char *str, va_list arg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			parse(str, i, arg);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			printed;

	va_start(arg, str);
	printed = print_str(*str, arg);
	va_end(arg);
	return (0);
}
