# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 14:31:06 by emedeiro          #+#    #+#              #
#    Updated: 2024/06/27 14:52:13 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	#Compiling Variables#
CC		 = cc
CFLAGS	 = -g -Wall -Wextra -Werror

	#Names#
NAME	= push_swap

	#LIBFT Variables#
LIBFT		= ./libft/libft.a

	#Sources#
SRCS =	algorithm_utils.c algorithm.c big_sort_utils.c insert_stacks.c \
		push_swap.c push.c reverse_rotate.c rotate.c swap.c verify_args.c
OBJS = $(SRCS:.c=.o)
##################### MAKEFILE RULES ##########################

all: $(LIBFT) $(NAME)

clean:
	${MAKE} clean -C ./libft
	rm -rf $(OBJS)
	
fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

################# MAKING MAIN PROGRAM ##################################

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft 

################################# Making LIBFT #########################
$(LIBFT):
	${MAKE} -C ./libft