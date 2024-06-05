# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 20:53:50 by emedeiro          #+#    #+#              #
#    Updated: 2024/06/05 16:20:22 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			####		Variables     ####
NAME_CLIENT = client
NAME_SERVER = server

			###		LIBFT Variables		###
LIBFT		= ./libft/libft.a

			####	Compiling Variables	####
CC 	   = cc
CFLAGS = -Wall -Wextra -Werror

			####Sources Variables####
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

			####		Rules			####
all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) -L./libft -lft

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) -L./libft -lft

$(LIBFT):
	${MAKE} -C ./libft

clean:
	${MAKE} clean -C ./libft
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	${MAKE} fclean -C ./libft
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all