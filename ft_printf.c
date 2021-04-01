/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/01 17:49:58 by fholwerd      ########   odam.nl         */
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

int	parse(const char *str, size_t pos, t_tags *tags)
{
	parse_flags();
	parse_width();
	parse_precision();
	parse_size();
	parse_conversion();
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	t_tags	*tags;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = parse(str, i, tags);
		}
		i++;
	}
	va_end(arg);
	return (0);
}
