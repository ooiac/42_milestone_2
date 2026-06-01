NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O2
MATH		= -lm
MLX_PATH	= minilibx-linux/
MLX_LIB		= $(MLX_PATH)libmlx.a
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11

SRCDIR		= src/
SRCDIR_BONUS = src_bonus/
OBJDIR		= obj/
INC			= -Iincludes -I$(MLX_PATH)
INC_BONUS	= -Iincludes_bonus -I$(MLX_PATH)

SOURCES		= fractol.c \
			  init.c \
			  render.c \
			  events.c \
			  math_utils.c \
			  color_utils.c \
			  string_utils.c \
			  equations.c

BONUS_SOURCES = fractol_bonus.c \
			    init_bonus.c \
			    render_bonus.c \
			    events_bonus.c \
			    math_utils_bonus.c \
			    color_utils_bonus.c \
			    string_utils_bonus.c \
			    equations_bonus.c \
			    key_bonus.c

OBJECTS		= $(SOURCES:%.c=$(OBJDIR)%.o)
BONUS_OBJECTS = $(BONUS_SOURCES:%.c=$(OBJDIR)%.o)

all: $(MLX_LIB) $(NAME)

bonus: $(MLX_LIB) $(OBJDIR) $(BONUS_OBJECTS)
	$(CC) $(BONUS_OBJECTS) $(MLX_FLAGS) $(MATH) -o $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	$(CC) $(OBJECTS) $(MLX_FLAGS) $(MATH) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR)%_bonus.o: $(SRCDIR_BONUS)%_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

# Special rules for bonus files without _bonus suffix in source names
$(OBJDIR)fractol_bonus.o: $(SRCDIR_BONUS)fractol_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)init_bonus.o: $(SRCDIR_BONUS)init_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)render_bonus.o: $(SRCDIR_BONUS)render_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)events_bonus.o: $(SRCDIR_BONUS)events_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)equations_bonus.o: $(SRCDIR_BONUS)equations_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)key_bonus.o: $(SRCDIR_BONUS)key_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)math_utils_bonus.o: $(SRCDIR_BONUS)math_utils_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)color_utils_bonus.o: $(SRCDIR_BONUS)color_utils_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

$(OBJDIR)string_utils_bonus.o: $(SRCDIR_BONUS)string_utils_bonus.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC_BONUS) -DBONUS -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re