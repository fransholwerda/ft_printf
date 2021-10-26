/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_digits.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 12:57:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	int_digits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

int	uint_digits(u_int32_t n)
{
	int	digits;

	digits = 1;
	while (n >= 10)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

int	hex_digits(u_int32_t n)
{
	int	digits;

	digits = 1;
	while (n >= 16)
	{
		digits++;
		n = n / 16;
	}
	return (digits);
}

int	pointer_digits(u_int64_t n)
{
	int	digits;

	digits = 1;
	while (n >= 16)
	{
		digits++;
		n = n / 16;
	}
	return (digits);
}
