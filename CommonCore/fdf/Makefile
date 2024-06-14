# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 20:16:11 by emedeiro          #+#    #+#              #
#    Updated: 2024/06/14 17:36:36 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	#Compiling Variables#
CC		 = cc
CFLAGS	 = -g -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11 -lm

	#Names#
NAME	= fdf

##################### MAKEFILE VARIABLES ###############################
LIBFT		= libft/libft.a
MLX			= minilibx_macos/libmlx.a

##################### MAKEFILE SOURCES #################################
SRCS =	fdf.c file_manipulation.c map_manipulation.c matrix_manipulation.c \
		point_manipulation.c

##################### MAKEFILE OBJS ####################################
OBJS = $(SRCS:.c=.o)

##################### MAKEFILE RULES ###################################

all: $(LIBFT) $(MLX) $(NAME)

clean:
	${MAKE} clean -C ./libft
	${MAKE} clean -C ./minilibx_macos
	rm -rf $(OBJS)
	
fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

################# MAKING MAIN PROGRAM ##################################
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft -L./minilibx_macos -lmlx $(MLX_FLAGS)

################################# Making LIBFT #########################
$(LIBFT):
	${MAKE} -C ./libft

################################# Making MLX ###########################
$(MLX):
	${MAKE} -C ./minilibx_macos