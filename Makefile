# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/15 16:51:44 by fholwerd      #+#    #+#                  #
#    Updated: 2021/10/26 19:34:05 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_CONVERSION = conversion/convert_c.c \
	conversion/convert_d.c \
	conversion/convert_p.c \
	conversion/convert_percent.c \
	conversion/convert_s.c \
	conversion/convert_u.c \
	conversion/convert_x.c
SRC_PARSING = parsing/parse_conversion.c \
	parsing/parse_flags.c \
	parsing/parse_precision.c \
	parsing/parse_size.c \
	parsing/parse_width.c \
	parsing/parse.c
SRC_UTILITY = utility/count_digits.c \
	utility/count_skip.c \
	utility/ft_atoi.c \
	utility/ft_isdigit.c \
	utility/ft_putchar.c \
	utility/ft_putnbr.c \
	utility/ft_putstr.c \
	utility/ft_strchr.c \
	utility/ft_strlen.c \
	utility/print_blank.c \
	utility/struct_utility.c
SRCS = ft_printf.c $(SRC_CONVERSION) $(SRC_PARSING) $(SRC_UTILITY)
SRCS_BONUS = 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADERS = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
