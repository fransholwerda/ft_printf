/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 12:42:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 17:10:54 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_putstr(char *str, t_tags *tags)
{
	if (!tags->precision_true || tags->precision > ft_strlen(str))
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, str, tags->precision));
}
