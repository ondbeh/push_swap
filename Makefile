NAME = push_swap

# Commands
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Files
SRCS = push_swap.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

# Rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(LIBFT_FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Create obj/ directory if it doesn't exist
$(OBJ_DIR):
	@echo "Creating directory $(OBJ_DIR)..."
	@mkdir -p $(OBJ_DIR)

# Build the libft library by calling its Makefile
$(LIBFT):
	@echo "Building libft library..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) all

# Rule to clean up object files
clean:
	@echo "Cleaning object files..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) -r $(OBJ_DIR)

# Rule to clean up object files and the executables
fclean: clean
	@echo "Cleaning all files..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

# Rule to rebuild everything from scratch
re: fclean all

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re