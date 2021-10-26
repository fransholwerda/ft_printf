/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 16:35:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_size(const char *str, t_tags *tags)
{
	while (str[tags->pos] == 'h' || str[tags->pos] == 'l')
	{
		if (str[tags->pos] == 'l' && str[tags->pos + 1] == 'l')
		{
			tags->size = 1;
			tags->pos += 2;
		}
		else if (str[tags->pos] == 'l')
		{
			tags->size = 2;
			tags->pos++;
		}
		else if (str[tags->pos] == 'h' && str[tags->pos + 1] == 'h')
		{
			tags->size = 3;
			tags->pos += 2;
		}
		else if (str[tags->pos] == 'h')
		{
			tags->size = 4;
			tags->pos++;
		}
	}
}
