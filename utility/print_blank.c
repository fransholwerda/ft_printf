/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_blank.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 14:03:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/29 14:22:55 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	print_blank(int length)
{
	char	*str;
	int		i;

	str = (char *)malloc(length * sizeof(char) + 1);
	if (!str)
		return (-1);
	i = 0;
	while (i < length)
	{
		str[i] = ' ';
		i++;
	}
	str[length] = '\0';
	write(1, str, length);
	free(str);
	return (1);
}
