/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 17:17:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/26 17:17:27 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h> //REMOVE THIS LATER

typedef struct s_tags
{
	int		printed;
	int		pos;
	int		tag_pos;
	int		flag_minus;
	int		flag_plus;
	int		flag_zero;
	int		flag_space;
	int		flag_hash;
	int		width;
	int		precision;
	int		precision_true;
	int		size;
	char	type;
}			t_tags;

int		ft_printf(const char *s, ...);

int		ft_putchar(char c);
int		ft_putstr(char *str, t_tags *tags);
int		ft_atoi(const char *nptr);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		count_skip(const char *str, long int i);
int		int_digits(int n);
int		uint_digits(u_int32_t n);
int		hex_digits(u_int32_t n);
int		pointer_digits(u_int64_t n);
int		print_pzero(int length);
int		print_blank(int length, t_tags *tags);
int		ft_isdigit(int c);
void	ft_putint(int n, t_tags *tags);
void	ft_putuint(u_int32_t n, t_tags *tags);
void	ft_puthex(u_int32_t n, t_tags *tags, int big, int first);
void	ft_putpointer(u_int64_t n, t_tags *tags);

void	ft_lstnew(t_tags *tags);
void	ft_lstreset(t_tags *tags);

void	parse(const char *str, va_list *arg, t_tags *tags);
void	parse_precision(const char *str, va_list *arg, t_tags *tags);
void	parse_size(const char *str, t_tags *tags);
void	parse_conversion(const char *str, va_list *arg, t_tags *tags);
void	parse_flags(const char *str, t_tags *tags);
void	parse_width(const char *str, va_list *arg, t_tags *tags);

void	convert_c(t_tags *tags, va_list *arg);
void	convert_d(t_tags *tags, va_list *arg);
void	convert_p(t_tags *tags, va_list *arg);
void	convert_s(t_tags *tags, va_list *arg);
void	convert_u(t_tags *tags, va_list *arg);
void	convert_x(t_tags *tags, va_list *arg, int big);
void	convert_percent(t_tags *tags);

#endif
