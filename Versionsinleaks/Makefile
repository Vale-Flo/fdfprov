# Nombre del ejecutable
NAME = fdf

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Directorios
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = libs/libft
MLX_DIR = minilibx-linux

# Archivos fuente
SRC_FILES = arrows.c draw.c inputs.c main.c map_parser.c points.c render_utils.c utils.c ft_free.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Regla principal
all: $(NAME)

# Crear el ejecutable
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Compilar archivos .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Compilar libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compilar minilibx
$(MLX):
	@make -C $(MLX_DIR)

# Limpiar archivos de objeto
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

# Limpiar todo
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

# Reconstruir todo
re: fclean all

# Phony targets
.PHONY: all clean fclean re
