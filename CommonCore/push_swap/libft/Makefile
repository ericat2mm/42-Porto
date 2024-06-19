# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 11:58:20 by emedeiro          #+#    #+#              #
#    Updated: 2024/06/19 19:32:33 by emedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nome da biblioteca

NAME = libft.a

#compiladores e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#comandos para criar biblioteca estatica
ARFLAGS = ar rc

SRCS =  ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_tolower.c ft_atoi.c\
	     ft_isdigit.c ft_memmove.c ft_strlen.c ft_toupper.c ft_bzero.c\
	     ft_isprint.c ft_memset.c ft_strncmp.c ft_isalnum.c ft_memchr.c\
	     ft_strchr.c ft_strnstr.c ft_isalpha.c ft_memcmp.c ft_strlcat.c \
	     ft_strrchr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	     ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c\
	     ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_putendl_fd.c \
		 ft_print_base.c ft_print_char.c ft_print_ptr.c ft_print_str.c \
		 ft_printf.c get_next_line.c get_next_line_utils.c \

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	     ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARFLAGS) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS) $(OBJS)
	$(ARFLAGS) $(NAME) $(BONUS_OBJS) $(OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

