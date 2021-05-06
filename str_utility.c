/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 09:52:25 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/02 13:42:17 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	count_digits(const char *str, long int i)
{
	size_t	count;

	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	return (count);
}
