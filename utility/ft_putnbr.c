/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:54:35 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 11:23:36 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_putnbr(int n, t_tags *tags)
{
	if (!(tags->precision_true && !tags->precision && !n))
	{
		if (n == -2147483648)
		{
			tags->printed += write(1, "-2", 2);
			ft_putnbr(147483648, tags);
		}
		else if (n < 0)
		{
			tags->printed += ft_putchar('-');
			ft_putnbr(n * -1, tags);
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10, tags);
			tags->printed += ft_putchar((n % 10) + '0');
		}
		else
			tags->printed += ft_putchar((n % 10) + '0');
	}
}
