/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/03/05 19:03:31 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

static char	*get_var(const char *str, size_t i, va_list arg, size_t arg_cnt)
{
	if (str[i + 1] == 'c')
		return (get_char(arg, arg_cnt));
	else if (str[i + 1] == 'd')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'e')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'f')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'i')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'o')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 's')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'u')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'x')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'd')
		return (get_double(arg, arg_cnt));
	else if (str[i + 1] == 'd')
		return (get_double(arg, arg_cnt));
	//DO SOMETHING HERE
}

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
