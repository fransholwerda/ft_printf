/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/24 18:21:46 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int	i;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			write(1, &arg[0], 5);
			i += 2;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (0);
}
