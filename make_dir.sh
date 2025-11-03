#!/usr/bin/env bash
set -euo pipefail

# --- 使い方チェック ---
if [[ $# -lt 1 || ! $1 =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <max_number> [prefix]"
  echo "例: $0 7        -> ex00..ex07 を作成"
  echo "例: $0 12 task  -> task00..task12 を作成"
  exit 1
fi

max="$1"
prefix="${2:-ex}"

# --- ゼロ埋め桁数を自動決定 ---
width=${#max}
(( width < 2 )) && width=2

# --- 各ディレクトリ作成とMakefile生成 ---
for i in $(seq 0 "$max"); do
  dir=$(printf "%s%0*d" "$prefix" "$width" "$i")
  mkdir -p "$dir"

  makefile="$dir/Makefile"
  if [[ ! -f "$makefile" ]]; then
    cat > "$makefile" << 'EOF'
# Basic Makefile Template
NAME = a.out
SRCS_FILE  = main 

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
EOF
    echo "created: $dir (with Makefile)"
  else
    echo "exists:  $dir (Makefile already present)"
  fi
done
