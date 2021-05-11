/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_blank.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 14:03:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 17:28:43 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	print_blank(int length, t_tags *tags)
{
	char	*str;
	int		i;
	int		printed;

	if (length > 0)
	{
		str = (char *)malloc(length * sizeof(char) + 1);
		if (!str)
			return (0);
		i = 0;
		while (i < length)
		{
			if (tags->flag_zero >= 1 && tags->flag_minus == 0)
				str[i] = '0';
			else
				str[i] = ' ';
			i++;
		}
		str[length] = '\0';
		printed = write(1, str, length);
		free(str);
		return (printed);
	}
	else
		return (0);
}
