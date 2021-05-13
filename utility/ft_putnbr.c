/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:54:35 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/13 15:52:35 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_putint(int n, t_tags *tags)
{
	if (!(tags->precision_true && !tags->precision && !n))
	{
		if (n == -2147483648)
		{
			tags->printed += write(1, "2", 1);
			ft_putint(147483648, tags);
		}
		else if (n < 0)
			ft_putint(n * -1, tags);
		else if (n >= 10)
		{
			ft_putint(n / 10, tags);
			tags->printed += ft_putchar((n % 10) + '0');
		}
		else
			tags->printed += ft_putchar((n % 10) + '0');
	}
}

void	ft_putuint(u_int32_t n, t_tags *tags)
{
	if (!(tags->precision_true && !tags->precision && !n))
	{
		if (n >= 10)
			ft_putuint(n / 10, tags);
		tags->printed += ft_putchar((n % 10) + '0');
	}
}

void	ft_puthex(u_int32_t n, t_tags *tags, int big)
{
	char	*small_hex;
	char	*big_hex;

	small_hex = "0123456789abcdef";
	big_hex = "0123456789ABCDEF";
	if (!(tags->precision_true && !tags->precision && !n))
	{
		if (n >= 16)
			ft_puthex(n / 16, tags, big);
		if (big)
			tags->printed += ft_putchar(big_hex[n % 16]);
		else
			tags->printed += ft_putchar(small_hex[n % 16]);
	}
}

void	ft_putpointer(u_int64_t n, t_tags *tags)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (!(tags->precision_true && !tags->precision && !n))
	{
		if (n >= 16)
			ft_putpointer(n / 16, tags);
		tags->printed += ft_putchar(hex[n % 16]);
	}
}
