/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 18:32:32 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/11 12:00:00 by fholwerd      ########   odam.nl         */
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
	int				printed;
	int				pos;
	int				tag_pos;
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
}					t_tags;

int		ft_printf(const char *s, ...);

int		ft_putchar_fd(char c, int fd);
int		ft_putstr(char *str, int length);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	count_digits(const char *str, long int i);
int		print_blank(int length, t_tags *tags);
int		ft_isdigit(int c);

t_tags	*ft_lstnew(void);
t_tags	*ft_lstlast(t_tags *lst);
void	ft_lstadd_back(t_tags **lst, t_tags *new);
void	ft_lstclear(t_tags **lst, void (*del)(void*));
void	print_tags(t_tags *tags);

int		parse(const char *str, va_list *arg, t_tags *tags);
int		parse_validate(t_tags *tags);
void	parse_precision(const char *str, va_list arg, t_tags *tags);
void	parse_size(const char *str, t_tags *tags);
void	parse_conversion(const char *str, va_list *arg, t_tags *tags);
void	parse_flags(const char *str, t_tags *tags);
void	parse_width(const char *str, va_list *arg, t_tags *tags);

void	convert_c(t_tags *tags, va_list *arg);

#endif
