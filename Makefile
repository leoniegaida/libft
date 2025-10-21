NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
PRF_DIR = ft_printf
GNL_DIR = get_next_line
OBJ_DIR = obj
INC_DIR = include

SRC = \
	$(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_isalnum.c $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isascii.c \
	$(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_memchr.c $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_memcpy.c \
	$(SRC_DIR)/ft_memmove.c $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c $(SRC_DIR)/ft_split.c $(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_striteri.c $(SRC_DIR)/ft_strjoin.c \
	$(SRC_DIR)/ft_strlcat.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_strnstr.c \
	$(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_toupper.c \
	\
	$(SRC_DIR)/$(PRF_DIR)/ft_handle_args.c \
	$(SRC_DIR)/$(PRF_DIR)/ft_print_addr.c \
	$(SRC_DIR)/$(PRF_DIR)/ft_print_char.c \
	$(SRC_DIR)/$(PRF_DIR)/ft_print_int_uint.c \
	$(SRC_DIR)/$(PRF_DIR)/ft_print_lowhex_uphex.c \
	$(SRC_DIR)/$(PRF_DIR)/ft_print_str.c \
	$(SRC_DIR)/$(PRF_DIR)/ft_printf.c \
	\
	$(SRC_DIR)/$(GNL_DIR)/get_next_line.c \
	$(SRC_DIR)/$(GNL_DIR)/get_next_line_utils.c \
	\
	$(SRC_DIR)/ft_atoi_base.c $(SRC_DIR)/ft_iofc.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@ar crs $@ $^
	@echo "$(NAME) successfully built!"

all: 
	@$(MAKE) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME) object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) full clean complete."

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

MAKEFLAGS += -s