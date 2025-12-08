NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = include
SRC_DIR = src
PRF_DIR = $(SRC_DIR)/ft_printf
GNL_DIR = $(SRC_DIR)/get_next_line
BON_DIR = $(SRC_DIR)/bonus
OBJ_DIR = obj

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
	$(PRF_DIR)/ft_handle_args.c \
	$(PRF_DIR)/ft_print_addr.c \
	$(PRF_DIR)/ft_print_char.c \
	$(PRF_DIR)/ft_print_int_uint.c \
	$(PRF_DIR)/ft_print_lowhex_uphex.c \
	$(PRF_DIR)/ft_print_str.c \
	$(PRF_DIR)/ft_printf.c \
	\
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	\
	$(SRC_DIR)/ft_atoi_base.c $(SRC_DIR)/ft_iofc.c $(SRC_DIR)/ft_count_entries.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS = \
	$(BON_DIR)/ft_lstadd_back.c $(BON_DIR)/ft_lstadd_front.c \
	$(BON_DIR)/ft_lstclear.c $(BON_DIR)/ft_lstdelone.c $(BON_DIR)/ft_lstiter.c \
	$(BON_DIR)/ft_lstlast.c $(BON_DIR)/ft_lstmap.c $(BON_DIR)/ft_lstnew.c \
	$(BON_DIR)/ft_lstsize.c

BONUS_OBJ = $(BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@ar crs $@ $^
	@echo "$(NAME) successfully built!"

all: 
	@$(MAKE) $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	@ar crs $(NAME) $^
	@echo "$(NAME) with bonus successfully built!"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME) object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) full clean complete."

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re bonus

MAKEFLAGS += -s
