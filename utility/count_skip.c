/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_skip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 09:52:25 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	count_skip(const char *str, long int i)
{
	int	count;

	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	return (count);
}
