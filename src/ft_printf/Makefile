NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_handle_args.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_addr.c \
		ft_print_int_uint.c \
		ft_print_lowhex_uphex.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
