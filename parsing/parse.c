/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:31:06 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 16:41:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	parse_validate(t_tags *tags)
{
	(void)tags;
	return (1);
}

int	parse(const char *str, long int i, t_tags *tags)
{
	size_t	start_i;

	start_i = i;
	while (ft_strchr("#0- +", str[i]))
		i = parse_flags(str, i, tags);
	while ((str[i] >= '1' && str[i] <= '9') || str[i] == '*')
		i = parse_width(str, i, tags);
	while (str[i] == '.' || str[i] == '*')
		i = parse_precision(str, i, tags);
	while (str[i] == 'h' || str[i] == 'l')
		i = parse_size(str, i, tags);
	if (ft_strchr("cspdiuxXnfge%", str[i]))
		i = parse_conversion(str, i, tags);
	tags->skip_pos = i - start_i;
	if (parse_validate(tags) == 1)
		return (i);
	else
		return (-1);
}
