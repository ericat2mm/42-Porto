
NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = push_a.c push_b.c push_ab.c print_stack.c reverse_rotate_a.c\
        reverse_rotate_b.c reverse_rotate_ab.c rotate_a.c rotate_b.c\
        rotate_ab.c swap_a.c swap_b.c swap_ab.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)   

$(NAME): $(OBJS) $(LIBFT)
    $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
    make -C $(LIBFT_DIR)

clean:
    rm -rf $(OBJS)
    make clean -C $(LIBFT_DIR)

fclean: clean
    rm -rf $(NAME)
    make fclean -C $(LIBFT_DIR)

re: fclean all