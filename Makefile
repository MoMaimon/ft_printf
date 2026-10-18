NAME = libftprintf.a
TEST_EXEC   = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs

SRC_DIR = src
BONUS_DIR = bonus
BUILD_DIR = build
LIBFT_DIR = libft

SRCS =  $(SRC_DIR)/ft_printf.c \
		${SRC_DIR}/selector.c \
		${SRC_DIR}/print_char.c \
		${SRC_DIR}/print_str.c \
		${SRC_DIR}/print_ptr.c \
		${SRC_DIR}/print_hex.c \
		${SRC_DIR}/print_mod.c \
		${SRC_DIR}/print_un.c \
		${SRC_DIR}/print_int.c \
		${SRC_DIR}/ft_dtox.c \

BONUS_SRCS = 	$(BONUS_DIR)/ft_printf_bonus.c \
				${BONUS_DIR}/selector_bonus.c \
				${BONUS_DIR}/print_char_bonus.c \
				${BONUS_DIR}/print_str_bonus.c \
				${BONUS_DIR}/print_ptr_bonus.c \
				${BONUS_DIR}/print_hex_bonus.c \
				${BONUS_DIR}/print_mod_bonus.c \
				${BONUS_DIR}/print_un_bonus.c \
				${BONUS_DIR}/print_int_bonus.c \
				${BONUS_DIR}/ft_dtox_bonus.c \


MAIN = $(SRC_DIR)/main.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BUILD_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJS) libft
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus: libft $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)
	touch .bonus

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFT_DIR)

test: $(NAME)
	$(CC) -g  $(SRC_DIR)/main.c $(NAME) libft/libft.a -o $(TEST_EXEC)
	./$(TEST_EXEC) | cat -e

clean:
	rm -rf $(BUILD_DIR)
	rm -f .bonus
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_EXEC)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus libft