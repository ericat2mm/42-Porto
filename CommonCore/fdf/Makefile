# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:10:18 by emedeiro          #+#    #+#              #
#    Updated: 2024/08/20 16:28:23 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

### NAME AND LIBRARIES ###
NAME = fdf
LIBX = ./minilibx-linux/libmlx.a
LIBFT = ./libft/libft.a

#### FLAGS ####
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror 
MINILIBX = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd -lm

## SOURCE FILES ##
SRCS = color_manipulation.c draw_manipulation.c draw_util.c  draw_util2.c\
	error_manipulation.c fdf.c init_manipulation.c key_manipulation.c \
	parse_manipulation.c parse_utils.c key_manipulation2.c \
	colors.c allocate_dots_malloc.c free.c

## OBJECT FILES ##
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBX) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled$(RESET)"

$(LIBFT):
	@make -C ./libft

$(LIBX):
	@make -C ./minilibx-linux

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux
	@echo "$(RED)Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all
