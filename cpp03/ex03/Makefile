# Basic Makefile Template
NAME = a.out
SRCS_FILE  = main ClapTrap ScavTrap FragTrap

SRCS = $(addsuffix .cpp, $(SRCS_FILE))
OBJ  = $(SRCS_FILE:=.o)
CXX  = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
