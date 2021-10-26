/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_blank.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 14:03:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:16:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_pzero(int length)
{
	char	*str;
	int		i;
	int		printed;

	if (length < 0)
		return (0);
	str = (char *)malloc(length * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < length)
	{
		str[i] = '0';
		i++;
	}
	str[length] = '\0';
	printed = write(1, str, length);
	free(str);
	return (printed);
}

int	print_blank(int length, t_tags *tags)
{
	char	*str;
	int		i;
	int		printed;

	if (length < 0)
		return (0);
	str = (char *)malloc(length * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < length)
	{
		if (tags->flag_zero && !tags->flag_minus)
			str[i] = '0';
		else if (tags->flag_zero && tags->precision < 0)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[length] = '\0';
	printed = write(1, str, length);
	free(str);
	return (printed);
}
