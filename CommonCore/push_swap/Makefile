# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 14:31:06 by emedeiro          #+#    #+#              #
#    Updated: 2024/06/19 19:31:32 by emedeiro         ###   ########.fr        #
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
SRCS =	handle_errors.c init_node_b.c init_node_a.c init_stack_a.c push_swap.c \
		push.c reverse_rotate.c rotate.c sort_stacks.c stack_utils.c swap.c

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
	${MAKE} --no-print-directory -C ./libft