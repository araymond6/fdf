# Program Names
NAME = fdf
LIBFT_A = libft/libft.a
MLX42_A = include/MLX42/build/libmlx42.a

# Compiler Variables
CC = gcc
ifdef DEBUG
	CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
else
	CFLAGS = -Wall -Werror -Wextra
endif
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

# Directories
SRC_DIR = ./src
INC_DIR = ./include
LIB_DIR = ./libft
BUILD_DIR = ./include/MLX42/build

# Sources & Objects
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:%.c=%.o)

# Compiler MLX42 Flags depending on the OS
OS = $(shell uname)
MAC = -I /include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
WINDOWS = 
LINUX = -I /include -ldl -lglfw -pthread -lm

# OS Check
ifeq ($(OS), Linux)
	MLXFLAGS2 = $(LINUX)
else ifeq ($(OS), Darwin)
	MLXFLAGS2 = $(MAC)
endif

# Colors
RESET = \033[0m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[93m
BLUE = \033[94m
MAGENTA = \033[95m
CYAN = \033[96m
WHITE = \033[97m

# Rules
all: mlx lib $(NAME) 

$(NAME): $(OBJS)
	@echo "\n$(GREEN)----------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Compiling files...$(GREEN) ---o---"
	@echo "\n$(GREEN)----------------------------------$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX42_A) $(MLXFLAGS) $(MLXFLAGS2) $(FLAGS) -o $(NAME)
	@echo "\n$(GREEN)------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)All tasks completed!$(GREEN) ---o---"
	@echo "\n$(GREEN)------------------------------------$(RESET)\n"

lib:
	@echo "\n$(GREEN)----------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Compiling LIBFT...$(GREEN) ---o---"
	@echo "\n$(GREEN)----------------------------------$(RESET)"
	make -C $(LIB_DIR)
	@echo "\n$(GREEN)-------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)LIBFT compiled!$(GREEN) ---o---"
	@echo "\n$(GREEN)-------------------------------$(RESET)\n"

mlx: 
	@echo "\n$(GREEN)----------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Compiling MLX42...$(GREEN) ---o---"
	@echo "\n$(GREEN)----------------------------------$(RESET)"
	(cd include/MLX42/ && cmake -B build/)
	(make -C $(BUILD_DIR))
	@echo "\n$(GREEN)-------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)MLX42 Compiled!$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)-------------------------------$(RESET)\n"

dep:
	@echo "\n$(GREEN)------------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Installing dependencies...$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)------------------------------------------$(RESET)"
	brew install glfw
	brew install cmake
	@echo "\n$(GREEN)-----------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)GLFW and CMake installed!$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)-----------------------------------------$(RESET)\n"

clean:
	@echo "\n$(GREEN)--------------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Removing all object files...$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)--------------------------------------------$(RESET)"
	rm -rf $(OBJS)
	make clean -C $(LIB_DIR)
	make clean -C $(BUILD_DIR)
	@echo "\n$(GREEN)-------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Object files removed!$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)-------------------------------------$(RESET)\n"

fclean: clean
	@echo "\n$(GREEN)---------------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Removing all program files...$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)---------------------------------------------$(RESET)"
	rm -rf $(NAME)
	rm -rf $(INC_DIR)/build
	make fclean -C $(LIB_DIR)
	@echo "\n$(GREEN)--------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Program files removed!$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)--------------------------------------$(RESET)\n"

re: fclean all

# To run program
run: all
	@echo "\n$(GREEN)---------------------------------------------"
	@echo "\n$(GREEN)---o--- $(MAGENTA)Executing program...$(GREEN) ---o---$(RESET)"
	@echo "\n$(GREEN)---------------------------------------------$(RESET)"
	./$(NAME) test_maps/42.fdf

# For debugging purposes
debug:
	make DEBUG=1 all