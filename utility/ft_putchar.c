/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 13:28:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 19:34:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
