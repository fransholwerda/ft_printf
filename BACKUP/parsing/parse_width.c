/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:36:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 17:39:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse_width(const char *str, long int i, t_tags *tags)
{
	size_t	digits;

	if (i < 0)
		return (i);
	digits = 0;
	if (tags->width > 0 || tags->width_star > 0)
		return (-1);
	else if (str[i] == '*')
	{
		tags->width_star++;
		i++;
	}
	else if (tags->width == 0)
	{
		digits = count_digits(str, i);
		tags->width = ft_atoi(&str[i]);
	}
	return (i + digits);
}
