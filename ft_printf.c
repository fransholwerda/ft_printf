/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 11:16:44 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_str(const char *str, va_list *arg, t_tags *tags)
{
	int	last_write;

	last_write = 0;
	while (str[tags->pos])
	{
		if (str[tags->pos] == '%')
		{
			tags->printed += write(1, str + last_write, tags->pos - last_write);
			tags->pos++;
			tags->tag_pos = tags->pos;
			parse(str, arg, tags);
			last_write = tags->pos;
		}
		else
			tags->pos++;
	}
	tags->printed += write(1, &str[last_write], ft_strlen(&str[last_write]));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_tags		*tags;
	int			error;

	tags = ft_lstnew();
	if (!tags)
		return (-1);
	va_start(arg, str);
	error = print_str(str, &arg, tags);
	if (error < 0)
		return (error);
	va_end(arg);
	return (tags->printed);
}
