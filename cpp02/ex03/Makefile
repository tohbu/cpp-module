# Basic Makefile Template
NAME = main

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(NAME).cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
