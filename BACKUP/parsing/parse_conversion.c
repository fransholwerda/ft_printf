/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conversion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:34:22 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/29 13:59:43 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	conv_ext(const char *str, long int i, t_tags *tags, va_list arg)
{
	if (str[i] == 'n')
		tags->type = 'n';
	else if (str[i] == 'f')
		tags->type = 'f';
	else if (str[i] == 'g')
		tags->type = 'g';
	else if (str[i] == 'e')
		tags->type = 'e';
	else if (str[i] == '%')
		convert_c(i, tags, arg);
	//tags->type = '%';
	return (i + 1);
}

int	parse_conversion(const char *str, long int i, t_tags *tags, va_list arg)
{
	if (i < 0)
		return (i);
	if (str[i] == 'c')
		i = convert_c(i, tags, arg);
	else if (str[i] == 's')
		tags->type = 's';
	else if (str[i] == 'p')
		tags->type = 'p';
	else if (str[i] == 'd')
		tags->type = 'd';
	else if (str[i] == 'i')
		tags->type = 'i';
	else if (str[i] == 'u')
		tags->type = 'u';
	else if (str[i] == 'x')
		tags->type = 'x';
	else if (str[i] == 'X')
		tags->type = 'X';
	else
		return (conv_ext(str, i, tags, arg));
	return (i);
}
