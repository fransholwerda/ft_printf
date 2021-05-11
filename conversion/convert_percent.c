/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_percent.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 16:56:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 17:05:41 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	convert_percent(t_tags *tags)
{
	char	c;

	c = '%';
	if (tags->width > 0)
	{
		if (tags->flag_minus >= 1)
		{
			tags->printed += write(1, &c, 1);
			tags->printed += print_blank(tags->width - 1, tags);
		}
		else
		{
			tags->printed += print_blank(tags->width - 1, tags);
			tags->printed += write(1, &c, 1);
		}
	}
	else
		tags->printed += write(1, &c, 1);
	tags->pos++;
}
