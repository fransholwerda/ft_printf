/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 16:13:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/15 13:19:24 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tags	*ft_lstnew(void)
{
	t_tags	*tags;

	tags = (t_tags *)malloc(sizeof(t_tags));
	if (tags == NULL)
		return (NULL);
	tags->skip_pos = 0;
	tags->flag_blank = 0;
	tags->flag_hash = 0;
	tags->flag_minus = 0;
	tags->flag_plus = 0;
	tags->flag_zero = 0;
	tags->precision = 0;
	tags->precision_star = 0;
	tags->size = 0;
	tags->type = '\0';
	tags->width = 0;
	tags->width_star = 0;
	tags->previous = NULL;
	tags->next = NULL;
	return (tags);
}

t_tags	*ft_lstlast(t_tags *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_tags **lst, t_tags *new)
{
	if (new)
	{
		if (!*lst)
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}

void	ft_lstclear(t_tags **lst, void (*del)(void*))
{
	if ((*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	free(*lst);
	*lst = NULL;
}

void	print_tags(t_tags *tags)
{
	while (tags)
	{
		printf("skip_pos: %d\nflag_blank: %d\nflag_hash: %d\nflag_minus: %d\nflag_plus: %d\nflag_zero: %d\nprecision: %d\nsize: %d\ntype: %c\nwidth: %d\n\n", tags->skip_pos, tags->flag_blank, tags->flag_hash, tags->flag_minus, tags->flag_plus, tags->flag_zero, tags->precision, tags->size, tags->type, tags->width);
		tags = tags->next;
	}
}
