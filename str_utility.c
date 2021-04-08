/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 09:52:25 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/08 14:23:09 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (needle[0] == '\0')
		return ((char *)&str[0]);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (i + j < len && str[i + j] != '\0' && str[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

size_t	count_digits(char *str, long int i)
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
