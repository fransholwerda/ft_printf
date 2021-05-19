/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utility.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 16:13:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/18 13:13:17 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_lstnew(t_tags *tags)
{
	tags->printed = 0;
	tags->pos = 0;
	tags->flag_blank = 0;
	tags->flag_hash = 0;
	tags->flag_minus = 0;
	tags->flag_plus = 0;
	tags->flag_zero = 0;
	tags->precision = 0;
	tags->precision_true = 0;
	tags->size = 0;
	tags->type = '\0';
	tags->width = 0;
}

void	ft_lstreset(t_tags *tags)
{
	tags->flag_blank = 0;
	tags->flag_hash = 0;
	tags->flag_minus = 0;
	tags->flag_plus = 0;
	tags->flag_zero = 0;
	tags->precision = 0;
	tags->precision_true = 0;
	tags->size = 0;
	tags->type = '\0';
	tags->width = 0;
}
