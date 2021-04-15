/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:30:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 16:36:35 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	long int	i;
	t_tags		*tags;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_lstadd_back(&tags, ft_lstnew());
			i = parse(str, i + 1, ft_lstlast(tags));
			printf("\n");
		}
		if (i < 0)
			return (i);
		i++;
	}
	va_start(arg, str);
	va_end(arg);
	print_tags(tags);
	ft_lstclear(&tags, free);
	return (0);
}
