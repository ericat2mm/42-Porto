# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:10:18 by emedeiro          #+#    #+#              #
#    Updated: 2024/08/13 11:29:51 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

###NAME AND LIBRARIES###
NAME = fdf
LIBX = ./minilibx_macos/libmlx.a
LIBFT = ./libft/libft.a

####FLAGS####
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L ./minilibx_macos -lmlx -lXext -lX11 -l

##SOURCE FILES##
SRCS = 	fdf.c draw_manipulation.c init_manipulation.c key_manipulation.c \
			render_manipulation.c free_manipulation.c read_manipulation.c

##OBJECT FILES##
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBX) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled$(RESET)"

$(LIBFT):
	@make -C ./libft

$(LIBX):
	@make -C ./minilibx_macos

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx_macos
	@echo "$(RED)Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all
