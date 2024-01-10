# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 23:09:11 by emedeiro          #+#    #+#              #
#    Updated: 2024/01/10 02:34:26 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = push_a.c push_b.c push_ab.c print_stack.c reverse_rotate_a.c\
        reverse_rotate_b.c reverse_rotate_ab.c rotate_a.c rotate_b.c\
        rotate_ab.c swap_a.c swap_b.c swap_ab.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS) $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME) $(LIBFT_DIR)

re: fclean all

