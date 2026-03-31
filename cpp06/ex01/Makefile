# Basic Makefile Template
NAME = a.out
<<<<<<< HEAD
SRCS_FILE  = main Data Serializer
=======
SRCS_FILE  = main 
>>>>>>> origin/cpp05

SRCS = $(addsuffix .cpp, $(SRCS_FILE))
OBJ  = $(SRCS_FILE:=.o)
CXX  = c++
<<<<<<< HEAD
CXXFLAGS = -Wall -Wextra -Werror -std=c++98   
=======
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  -pedantic
>>>>>>> origin/cpp05


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
