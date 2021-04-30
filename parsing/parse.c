/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:31:06 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/30 15:09:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse(const char *str, va_list arg, t_tags *tags)
{
	parse_flags(str, tags);
	parse_width(str, tags);
	parse_precision(str, tags);
	parse_size(str, tags);
	//if (ft_strchr("cspdiuxXnfge%", str[tags->pos]))
	parse_conversion(str, arg, tags);
	return (0);
}
