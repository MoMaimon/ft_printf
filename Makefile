NAME = libftprintf.a
TEST_EXEC   = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./src -I./libft
AR = ar rcs

SRC_DIR = src
BUILD_DIR = build
LIBFT_DIR = libft

SRCS =  $(SRC_DIR)/ft_printf.c


MAIN = $(SRC_DIR)/main.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

test: $(NAME)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(NAME) -o $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re