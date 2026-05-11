NAME     = PmergeMe
SRCS     = main.cpp 
OBJS     = $(SRCS:.cpp=.o)
DEPS     = $(SRCS:.cpp=.d)     
CXX      = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 -MMD -MP # -MMD -MP を追加

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# 生成された .d ファイル（依存関係メモリ）を読み込む
-include $(DEPS)

.PHONY: all clean fclean re