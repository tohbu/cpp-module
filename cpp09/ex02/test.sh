#!/bin/bash

EXE="./PmergeMe"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

# 1試行あたりのループ回数（最悪ケースを引き当てる確率を上げるため）
NUM_TRIALS=10

# 最悪計算数 S(n) のテーブル (n=1 to 21)
# 参照: OEIS A001768 (Ford-Johnson Comparison count)
declare -A WORST_CASES
WORST_CASES=([2]=1 [3]=3 [4]=5 [5]=7 [6]=10 [7]=13 [8]=16 [9]=19 [10]=22 [11]=26 [20]=62 [21]=66 [3000]=32911)

echo "--- PmergeMe Theoretical Limit Test ---"

ELEMENT_COUNTS=(2 3 4 5 6 7 8 9 10 11 20 21 3000)

for n in "${ELEMENT_COUNTS[@]}"; do
    LIMIT=${WORST_CASES[$n]}
    echo -e "\n${YELLOW}[Test: n = $n, Theoretical Limit S(n) = $LIMIT]${NC}"
    
    for i in $(seq 1 $NUM_TRIALS); do
        ARG=$(shuf -i 1-100000 -n $n | tr "\n" " ")
        RESULT=$($EXE $ARG 2>&1)
        
        if [ $? -ne 0 ]; then
            echo -e "${RED}  [Trial $i: CRASH]${NC} $RESULT"
            continue
        fi

        # 比較回数を抽出（"Number of comparisons: 42" のような出力を想定）
        COMP_COUNT=$(echo "$RESULT" | grep "Number of comparisons" | grep -oE '[0-9]+' | head -1)
        
        # ソート確認
        SORTED_EXPECTED=$(echo $ARG | tr " " "\n" | sort -n | tr "\n" " " | sed 's/ $//')
        SORTED_ACTUAL=$(echo "$RESULT" | grep "After:" | sed 's/After: //')
        
        if [ "$(echo $SORTED_ACTUAL | xargs)" != "$(echo $SORTED_EXPECTED | xargs)" ]; then
            echo -e "  [Trial $i] ${RED}SORT ERROR${NC}"
            continue
        fi

        # 比較回数の判定
        if [ -z "$COMP_COUNT" ]; then
            echo -e "  [Trial $i] ${YELLOW}Warning: Comparison count not found in output.${NC}"
        elif [ "$COMP_COUNT" -le "$LIMIT" ]; then
            echo -e "  [Trial $i] ${GREEN}PASS${NC} (Comparisons: $COMP_COUNT / $LIMIT)"
        else
            echo -e "  [Trial $i] ${RED}OVER LIMIT${NC} (Comparisons: $COMP_COUNT / $LIMIT)"
        fi
    done
done

echo -e "\n--- Test Completed ---"