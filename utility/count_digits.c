/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_digits.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/12 12:57:18 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/12 13:13:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	count_digits(int n)
{
	int digits;

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
