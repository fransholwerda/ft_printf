/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 13:28:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/29 13:28:18 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
