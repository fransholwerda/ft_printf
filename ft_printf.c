/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/08 09:55:11 by fholwerd      ########   odam.nl         */
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

int	parse(const char *str, long int i, t_tags *tags)
{
	if (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == ' ' || str[i] == '+' || str[i] == '*')
		i = parse_flags();
	if (str[i] >= '1' && str[i] <= '9')
		i = parse_width();
	if (str[i] == '.')
		i = parse_precision();
	if (str[i] == 'h' || str[i] == 'l')
		i = parse_size();
	if (ft_strnstr("cspdiuxXnfge%", str[i], 13))
		i = parse_conversion();
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	long int	i;
	t_tags		*tags;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = parse(str, i + 1, tags);
		if (i < 0)
			return (i);
		i++;
	}
	va_end(arg);
	return (0);
}
