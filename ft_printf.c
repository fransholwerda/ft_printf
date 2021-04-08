/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/08 14:43:45 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int	parse_flags(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
	if (str[i] == '#')
		tags->flag_hash++;
	else if (str[i] == '0')
		tags->flag_zero++;
	else if (str[i] == '-')
		tags->flag_minus++;
	else if (str[i] == ' ')
		tags->flag_blank++;
	else if (str[i] == '+')
		tags->flag_plus++;
	tags->skip_pos += 1;
	return (i + 1);
}

int	parse_width(const char *str, long int i, t_tags *tags)
{
	size_t	digits;

	if (i < 0)
		return (i);
	digits = 0;
	if (str[i] == '*')
	{
		tags->width_star++;
		i++;
	}
	else
	{	
		digits = count_digits(str[i], i);
		tags->width = ft_atoi
	}
	return (i + digits);
}

int	parse_precision(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
}

int	parse_size(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
}

int	parse_conversion(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
}

int	parse(const char *str, long int i, t_tags *tags)
{
	//PUT A LOOP hERE!!!!11!!!!!one!!!!!!1!!!!eleven!!!!
	if (ft_strnstr("#0- +", str[i], 6))
		i = parse_flags(str, i, tags);
	if (str[i] >= '1' && str[i] <= '9' ||  str[i] == '*')
		i = parse_width(str, i, tags);
	if (str[i] == '.' || str[i] == '*')
		i = parse_precision(str, i, tags);
	if (str[i] == 'h' || str[i] == 'l')
		i = parse_size(str, i, tags);
	if (ft_strnstr("cspdiuxXnfge%", str[i], 13))
		i = parse_conversion(str, i, tags);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	long int	i;
	t_tags		*tags;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tags = ft_lstnew();
			i = parse(str, i + 1, tags);
		}
		if (i < 0)
			return (i);
		i++;
	}
	va_end(arg);
	return (0);
}
