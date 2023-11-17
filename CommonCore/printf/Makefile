# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 12:31:52 by emedeiro          #+#    #+#              #
#    Updated: 2023/11/17 12:44:00 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = ar rc
CLEANFLAGS = rm -rf

SRCS = ft_printf.c ft_print_base.c ft_print_ptr.c ft_print_char.c ft_print_str.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(CLEANFLAGS) $(OBJS)

fclean: clean
	$(CLEANFLAGS) $(NAME)

re: flcean all
