/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 16:43:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/22 17:08:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	convert_c(const char *str, long int i, t_tags *tags, va_list arg)
{
	char	*print;
	int		width;

	width = 0;
	if (tags->width > 0)
		width = tags->width;
	else if (tags->width_star == 1)
		width = va_arg(arg, int);
	if (width > 0)
	{
		print = (char *)malloc((width * sizeof(char)) + 1);
		if (!print)
			return (-1);
		if (tags->flag_minus == 1)
			print[0] = str[i];
		else
			print[width] = str[i];
		write(1, print, width);
		free(print);
	}
	else
		write(1, &str[i], 1);
	return (i + 1);
}
