# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 23:09:11 by emedeiro          #+#    #+#              #
#    Updated: 2024/03/13 12:16:34 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			####		Colors 			####
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

			#### 	Color Menssages		####
MAKE_MESSAGE = "$(RED)MAKE done by emedeiro$(RESET)"
CLEAN_MESSAGE = "$(YELLOW)CLEAN done by emedeiro$(RESET)"
FCLEAN_MESSAGE = "$(GREEN)FCLEAN done by emedeiro$(RESET)"

			####		Variables     ####
NAME = push_swap

			####	Compiling Variables	####
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

			####	Libft Variables		####
LIBFT = ./libft_modified/libft.a

			####Sources Variables####
SRCS =	push.c swap.c rotate.c reverse_rotate.c\
		push_swap.c stacks_utils.c sort_stack.c\
		print_stack.c args.c main_logic.c sort_big_utils.c

OBJS = $(SRCS:.c=.o)


			####		Rules			####
all: $(LIBFT) $(NAME)
	@echo $(MAKE_MESSAGE)

clean:
	${MAKE} clean -C ./libft_modified
	rm -rf $(OBJS)
	@echo $(CLEAN_MESSAGE)

fclean: clean
	${MAKE} fclean -C ./libft_modified
	rm -rf $(NAME)
	@echo $(FCLEAN_MESSAGE)

re: fclean all

			####	Dependencies		####
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(LIBFT):
	${MAKE} -C ./libft_modified
