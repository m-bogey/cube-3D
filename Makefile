NAME = cub3D

# Obtenir les dimensions de l'écran
SCREEN_WIDTH := $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -d 'x' -f 1)
SCREEN_HEIGHT := $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -d 'x' -f 2)

# Directories
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
SRC_DIR = srcs
BUILD_DIR = .build
INCLUDES = includes

# Files
LIBFT = libft.a
MLX = libmlx.a

SRC_FILES = main.c \
			init.c \
			safe_exit.c \
			game.c \
			move_pix.c \
			img_pix_put.c \
			raycasting_3d.c \
			convert_to_3D.c \
			display_frames.c \
			mini_map/display_mini_map.c \
			mini_map/draw_pov.c \
			mini_map/draw_line.c \
			mini_map/draw_walls.c \
			parsing/free_details_and_map.c \
			parsing/parse_input.c \
			parsing/store_file_in_tab.c \
			parsing/is_multiple_path.c \
			parsing/is_whitespace.c \
			parsing/store_map_info.c \
			parsing/check_if_reach_map.c \
			parsing/store_map.c \
			parsing/convert_rgb_to_hexa.c \
			parsing/free.c \
			parsing/check_map/check_map.c \
			parsing/check_map/check_wall.c \
			parsing/check_map/check_map_info.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))
DEPS = $(OBJ:.o=.d)

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR) -I$(MLX_DIR) -Ofast -flto
SCREEN_FLAGS = -D SCREEN_WIDTH=$(SCREEN_WIDTH) -D SCREEN_HEIGHT=$(SCREEN_HEIGHT)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lm -lz -lXext -Ofast -flto
DFLAGS = -MMD -MP

.PHONY: all clean fclean re mlx libf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(SCREEN_FLAGS) $(LDFLAGS)

#$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
#	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

#$(BUILD_DIR):
#	mkdir -p $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(dir $(OBJ))

-include $(DEPS)

$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(BUILD_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: FORCE
FORCE:
