# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 16:57:53 by emedeiro          #+#    #+#              #
#    Updated: 2024/09/23 16:57:53 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME = philosophers
LIBFT = ./libft/libft.a

### FLAGS ###
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PFLAGS = -pthread

### SOURCES ###
srcs =	forks.c philo_options.c philosophers.c print_status.c \
		simulation_manipulation.c table_manipulation.c

objs = $(srcs:.c=.o)

### RULES ###
all: $(NAME)

$(NAME): $(objs)
	@$(CC) $(CFLAGS) $(PFLAGS) $(objs) $(LIBFT) -o $(NAME)
	@echo "Philosophers compiled"

$(LIBFT): 
	@make -C ./libft

clean:
	@rm -f $(objs)
	@make clean -C ./libft
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "Philosophers removed"

re: fclean all