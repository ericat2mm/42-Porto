# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:10:18 by emedeiro          #+#    #+#              #
#    Updated: 2024/08/14 08:00:18 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

### NAME AND LIBRARIES ###
NAME = fdf
LIBX = ./minilibx_macos/libmlx.a
LIBFT = ./libft/libft.a

#### FLAGS ####
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit


## SOURCE FILES ##
SRCS = 	bresenham_utils.c data_manipulation.c dimensions.c draw_manipulation.c \
		fdf.c free_manipulation.c init_manipulation.c key_manipulation.c \
		matrix_manipulation.c point_manipulation.c read_manipulation.c \
		render_manipulation.c screen_manipulation.c

## OBJECT FILES ##
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
