/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 13:51:47 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/22 13:52:10 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	overflow_check(long int value, int minus, const char c)
{
	if (((value * 10 * minus) > 922337203685477580 && c > 55)
		|| (value * 10 * minus) >= 9223372036854775800)
		return (-1);
	else if (((value * 10 * minus) < -922337203685477580 && c > 56)
		|| (value * 10 * minus) <= -9223372036854775800)
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	long int	value;
	int			minus;
	int			i;

	value = 0;
	minus = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (overflow_check(value, minus, nptr[i]) < 1)
			return (overflow_check(value, minus, nptr[i]));
		value = (value * 10) + (nptr[i] - 48);
		i++;
	}
	return ((int)(value * minus));
}
