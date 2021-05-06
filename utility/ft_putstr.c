/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/06 12:42:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/06 16:23:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_putstr(char *str, int length)
{
	if (length == 0)
		length = ft_strlen(str);
	return (write(1, str, length));
}
