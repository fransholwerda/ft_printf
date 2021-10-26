/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:36:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_flags(const char *str, t_tags *tags)
{
	while (ft_strchr("#0- +", str[tags->pos]))
	{
		if (str[tags->pos] == '#')
			tags->flag_hash++;
		else if (str[tags->pos] == '0')
			tags->flag_zero++;
		else if (str[tags->pos] == '-')
			tags->flag_minus++;
		else if (str[tags->pos] == ' ')
			tags->flag_space++;
		else if (str[tags->pos] == '+')
			tags->flag_plus++;
		tags->pos++;
	}
}
