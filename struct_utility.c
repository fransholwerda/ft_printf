/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 16:13:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/01 17:21:26 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tags	*ft_lstnew(void)
{
	t_tags	*tags;

	tags = (t_tags *)malloc(sizeof(t_tags));
	if (tags == NULL)
		return (NULL);
	tags->flag_blank = 0;
	tags->flag_hash = 0;
	tags->flag_minus = 0;
	tags->flag_plus = 0;
	tags->flag_zero = 0;
	tags->precision = 0;
	tags->size = 0;
	tags->type = '\0';
	tags->width = 0;
	tags->next = NULL;
	return (tags);
}
