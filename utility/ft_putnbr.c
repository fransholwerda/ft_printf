/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/11 15:54:35 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 17:54:36 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_putnbr(int n, t_tags *tags)
{
	if (n >= 10)
		ft_putnbr(n, tags);
	tags->printed += ft_putchar((n % 10) + '0');
}
