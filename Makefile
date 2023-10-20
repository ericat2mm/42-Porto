#nome da biblioteca e extensao
NAME = libft.a

#compilador e opcoes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#comandos para criar biblioteca estatica
ARFLAGS = ar rc

#lista de arquivos de codigo-fonte
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_split.c ft_itoa.c ft_putchar_fd.c \
	ft_putstr_fd.c

#gerar automaticamente a lista de arquivos de objeto
OBJS = $(SRC:.c=.o)

#alvo padrao
all: $(NAME)

#alvo para criar a biblioteca estatica
$(NAME): $(OBJS)
	$(ARFLAGS) $(NAME) $(OBJS)

#alvo para limpar os arquivos de objeto e a biblioteca
clean:
	rm -rf  $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
