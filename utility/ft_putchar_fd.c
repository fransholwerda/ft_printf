/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 13:28:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/02 11:26:16 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
