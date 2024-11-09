# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 08:26:51 by emedeiro          #+#    #+#              #
#    Updated: 2024/11/09 08:32:18 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = philosophers

LIBFT = ./Files/libft/libft.a

# Shell and printf
SHELL =		/bin/bash
UNAME =		$(shell uname -s)
PRINTF =	printf

# Compiler and flags
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
AR =		ar rcs
RM =		rm -f

# Directories
OBJ_DIR =	obj

# Colors
RED =		\033[0;31m
GREEN =		\033[0;32m
YELLOW =	\033[0;33m
BLUE =		\033[0;34m
PURPLE =	\033[0;35m
CYAN =		\033[0;36m
WHITE =		\033[0;37m
MAGENTA =	\033[0;35m
RESET =		\033[0m

# Source files
SRCS_PHILO =	./Files/initialization.c \
				./Files/launcher.c \
				./Files/simulation.c \
				./Files/utils.c

SRCS_MAIN =		main.c

# Objects
OBJS_PHILO =	$(SRCS_PHILO:%.c=$(OBJ_DIR)/%.o)
OBJS_MAIN =		$(SRCS_MAIN:%.c=$(OBJ_DIR)/%.o)

OBJS =		$(OBJS_PHILO) $(OBJS_MAIN)

# Counts
SRC_COUNT_TOT =	$(words $(SRCS_PHILO) $(SRCS_MAIN))
SRC_COUNT =		0

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(PRINTF) "$(RESET)[$(NAME)] $(GREEN)Compiling...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@$(PRINTF) "$(RESET)[$(NAME)] $(GREEN)Compiled successfully!$(RESET)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(eval SRC_COUNT=$(shell echo $$(($(SRC_COUNT)+1))))
	@$(PRINTF) "$(RESET)[$(NAME)] $(call set_color,$(dir $<))Compiling $(SRC_COUNT)/$(SRC_COUNT_TOT) $(notdir $<)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./Files/libft 

clean:
	@$(RM) $(OBJS)
	@$(PRINTF) "$(RESET)[$(NAME)] $(RED)Removed object files$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(PRINTF) "$(RESET)[$(NAME)] $(RED)Removed $(NAME)$(RESET)\n"

re: fclean all