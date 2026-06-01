NAME = push_swap

# Source files
SRCS = main.c \
       ft_split_ps.c \
       stack_init.c \
       stack_utils.c \
       handle_errors.c \
       utils.c \
       commands.c \
       swap_commands.c \
       push_commands.c \
       rotate_commands.c \
       rotate.c \
       init_a_to_b.c \
       init_b_to_a.c \
       sort_three.c \
       sort_stacks.c

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re