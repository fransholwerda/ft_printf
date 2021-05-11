/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conversion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:34:22 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 17:06:10 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	conv_ext(const char *str, va_list *arg, t_tags *tags)
{
	if (str[tags->pos] == 'n')
		tags->type = 'n';
	else if (str[tags->pos] == 'f')
		tags->type = 'f';
	else if (str[tags->pos] == 'g')
		tags->type = 'g';
	else if (str[tags->pos] == 'e')
		tags->type = 'e';
	else if (str[tags->pos] == '%')
		convert_percent(tags);
	(void)arg;
	//tags->type = '%';
}

void	parse_conversion(const char *str, va_list *arg, t_tags *tags)
{
	if (str[tags->pos] == 'c')
		convert_c(tags, arg);
	else if (str[tags->pos] == 's')
		convert_s(tags, arg);
	else if (str[tags->pos] == 'p')
		tags->type = 'p';
	else if (str[tags->pos] == 'd')
		tags->type = 'd';
	else if (str[tags->pos] == 'i')
		tags->type = 'i';
	else if (str[tags->pos] == 'u')
		tags->type = 'u';
	else if (str[tags->pos] == 'x')
		tags->type = 'x';
	else if (str[tags->pos] == 'X')
		tags->type = 'X';
	else
		conv_ext(str, arg, tags);
}
