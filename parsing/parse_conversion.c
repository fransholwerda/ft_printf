/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conversion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:34:22 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 16:49:15 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	parse_conversion_extended(const char *str, long int i, t_tags *tags)
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
		tags->type = '%';
	return (i + 1);
}

int	parse_conversion(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
	if (str[i] == 'c')
		tags->type = 'c';
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
		return (parse_conversion_extended(str, i, tags));
	return (i + 1);
}
