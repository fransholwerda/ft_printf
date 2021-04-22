/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:32:32 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/04/22 12:53:14 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h> //REMOVE THIS LATER

typedef struct s_tags
{
	int				skip_pos;
	int				flag_minus;
	int				flag_plus;
	int				flag_zero;
	int				flag_blank;
	int				flag_hash;
	int				width;
	int				width_star;
	int				precision;
	int				precision_star;
	int				size;
	char			type;
	struct s_tags	*next;
	struct s_tags	*previous;
}				t_tags;

int		ft_printf(const char *s, ...);

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	count_digits(const char *str, long int i);

t_tags	*ft_lstnew(void);
t_tags	*ft_lstlast(t_tags *lst);
void	ft_lstadd_back(t_tags **lst, t_tags *new);
void	ft_lstclear(t_tags **lst, void (*del)(void*));
void	print_tags(t_tags *tags);

int		parse(const char *str, long int i, t_tags *tags, va_list arg);
int		parse_validate(t_tags *tags);
int		parse_precision(const char *str, long int i, t_tags *tags);
int		parse_size(const char *str, long int i, t_tags *tags);
int		parse_conversion(const char *str, long int i, t_tags *tags, \
		va_list arg);
int		parse_flags(const char *str, long int i, t_tags *tags);
int		parse_width(const char *str, long int i, t_tags *tags);

#endif
