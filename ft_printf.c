/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/10 19:20:09 by fholwerd      ########   odam.nl         */
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
	if (tags->width > 0 || tags->width_star > 0)
		return (-1);
	else if (str[i] == '*')
	{
		tags->width_star++;
		i++;
	}
	else if (tags->width == 0)
	{	
		digits = count_digits(str[i], i);
		tags->width = ft_atoi(&str[i]);
	}
	return (i + digits);
}

int	parse_precision(const char *str, long int i, t_tags *tags)
{
	size_t	digits;

	if (i < 0)
		return (i);
	digits = 0;
	if (tags->precision > 0 || tags->precision_star > 0)
		return (-1);
	else if (str[i] == '*')
	{
		tags->precision_star = 1;
		i++;
	}
	else
	{
		digits = count_digits(str[i], i);
		tags->precision = ft_atoi(&str[i]);
	}
	return (i + digits)
}

int	parse_size(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		tags->size = 1;
		return (i + 2);
	}
	else if (str[i] == 'l')
		tags->size = 2;
	else if (str[i] == 'h' && str[i + 1] == 'h')
	{
		tags->size = 3;
		return (i + 2);
	}
	else if (str[i] == 'h')
		tags->size = 4;
	return (i + 1);
}

int	parse_conversion_extended(const char *str, long int i, t_tags *tags)
{
	if (str[i] == 'n')
		tags->type = 'n';
	else if (str[i] == 'f')
		tags->type = 'f';
	else if (str[i] == 'g')
		tags->type = 'g';
	else if (str[i] == 'e')
		tags->type = 'e';
	else if (str[i] == '%')
		tags->type = '%';
	return (i + 1);
}

int	parse_conversion(const char *str, long int i, t_tags *tags)
{
	if (i < 0)
		return (i);
	if (str[i] == 'c')
		tags->type = 'c';
	else if (str[i] == 's')
		tags->type = 's';
	else if (str[i] == 'p')
		tags->type = 'p';
	else if (str[i] == 'd')
		tags->type = 'd';
	else if (str[i] == 'i')
		tags->type = 'i';
	else if (str[i] == 'u')
		tags->type = 'u';
	else if (str[i] == 'x')
		tags->type = 'x';
	else if (str[i] == 'X')
		tags->type = 'X';
	else
		return (parse_conversion_extended(str, i, tags));
	return (i + 1);
}

int	parse(const char *str, long int i, t_tags *tags)
{
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
			if (!tags)
				tags = ft_lstnew();
			else
			{
				tags->next = ft_lstnew();
				tags = tags->next;
			}
			i = parse(str, i + 1, tags);
		}
		if (i < 0)
			return (i);
		i++;
	}
	va_end(arg);
	return (0);
}
