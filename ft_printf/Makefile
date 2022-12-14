# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wextra -Wall -Werror -c

NAME = libftprintf.a

LIB = libft/libft.a 
LIBFT_OBJS = libft/*.o

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_hex.c ft_putnbr.c ft_uitoa.c ft_putunbr.c ft_putptr.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re