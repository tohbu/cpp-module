# Basic Makefile Template
NAME = a.out
SRCS_FILE  = main 

SRCS = $(addsuffix .cpp, $(SRCS_FILE))
OBJ  = $(SRCS_FILE:=.o)
CXX  = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  -pedantic


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
