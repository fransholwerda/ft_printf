/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:31:06 by fholwerd      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/05/11 11:16:05 by fholwerd      ########   odam.nl         */
=======
/*   Updated: 2021/05/06 12:31:00 by fholwerd      ########   odam.nl         */
>>>>>>> 4292c3778eecdd403e83ad4b196d16b46525dc43
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse(const char *str, va_list *arg, t_tags *tags)
{
	parse_flags(str, tags);
	parse_width(str, arg, tags);
	parse_precision(str, arg, tags);
	parse_size(str, tags);
	parse_conversion(str, arg, tags);
	return (0);
}
