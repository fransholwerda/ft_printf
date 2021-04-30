/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 09:52:25 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 12:48:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}


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
