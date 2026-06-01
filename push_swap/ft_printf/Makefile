# **************************************************************************** #
#                                 ft_printf                                    #
# **************************************************************************** #

NAME        = libftprintf.a

# Fontes
SRCS        = ft_printf.c \
              char_utils.c \
              number_utils.c \
              ptr_utils.c \
              libft_utils.c \
              libft_utils_2.c

# Objetos
OBJS        = $(SRCS:.c=.o)

# Compilador e flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Regra principal
all: $(NAME)

# Cria a biblioteca estática
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Limpa objetos
clean:
	rm -f $(OBJS)

# Limpa objetos e a lib
fclean: clean
	rm -f $(NAME)

# Recompila tudo
re: fclean all

.PHONY: all clean fclean re
