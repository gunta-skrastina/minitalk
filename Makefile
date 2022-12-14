# _*_ MakeFile _*_

CC = gcc

CFLAGS = -Wextra -Wall -Werror

NAME = libftprintf.a
CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c

OBJS = $(SRCS:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

all: $(NAME) $(CLIENT) $(SERVER)

$(NAME):
	$(MAKE) -C ft_printf
	cp ft_printf/$(NAME) $(NAME)

$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) $(NAME) -o $(CLIENT)

$(SERVER): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) $(NAME) -o $(SERVER)

clean:
	rm -f $(OBJ_C) $(OBJ_S)
	make clean -C ft_printf

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(NAME)
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re