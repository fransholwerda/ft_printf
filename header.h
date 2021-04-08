/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:32:32 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/08 09:52:56 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_tags
{
	int				flag_minus;
	int				flag_plus;
	int				flag_zero;
	int				flag_blank;
	int				flag_hash;
	int				width;
	int				precision;
	int				size;
	char			type;
	struct s_tags	*next;
}				t_tags;

int		ft_printf(const char *s, ...);
char	*ft_strnstr(const char *str, const char *needle, size_t len);

#endif
