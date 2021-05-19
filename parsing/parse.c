/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:31:06 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/19 15:18:58 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse(const char *str, va_list *arg, t_tags *tags)
{
	parse_flags(str, tags);
	parse_width(str, arg, tags);
	parse_precision(str, arg, tags);
	parse_size(str, tags);
	parse_conversion(str, arg, tags);
}
