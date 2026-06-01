# **************************************************************************** #
#                                  Minitalk                                   #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

SRCS_MANDATORY = server.c client.c
SRCS_BONUS = server_bonus.c client_bonus.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): server.o
	$(CC) $(CFLAGS) -o $(NAME_SERVER) server.o $(LIBFT) $(LIBFT_INC)

$(NAME_CLIENT): client.o
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) client.o $(LIBFT) $(LIBFT_INC)

bonus: $(LIBFT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): server_bonus.o
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) server_bonus.o $(LIBFT) $(LIBFT_INC)

$(NAME_CLIENT_BONUS): client_bonus.o
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) client_bonus.o $(LIBFT) $(LIBFT_INC)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f *.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
