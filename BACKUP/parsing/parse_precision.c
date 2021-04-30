/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:35:32 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 16:35:40 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse_precision(const char *str, long int i, t_tags *tags)
{
	size_t	digits;

	if (i < 0)
		return (i);
	digits = 0;
	i++;
	if (tags->precision > 0 || tags->precision_star > 0)
		return (-1);
	else if (str[i] == '*')
	{
		tags->precision_star++;
		i++;
	}
	else
	{
		digits = count_digits(str, i);
		tags->precision += ft_atoi(&str[i]);
	}
	return (i + digits);
}
