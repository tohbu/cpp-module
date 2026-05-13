#!/bin/bash

# 実行ファイルの名前（適宜変更してください）
EXE="./RPN"

# 色の設定
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "--- RPN Program Robustness Test ---"

# テスト実行関数の定義
test_case() {
    local input="$1"
    local expected="$2"
    
    echo -n "Test: \"$input\" -> "
    actual=$($EXE "$input" 2>&1)
    
    # 期待値が "Error" の場合、出力の先頭5文字が "Error" かをチェック
    if [ "$expected" == "Error" ]; then
        if [[ "$actual" =~ ^Error ]]; then
            echo -e "${GREEN}[PASS]${NC} (Actual: $actual)"
        else
            echo -e "${RED}[FAIL]${NC}"
            echo "   Expected starting with: Error"
            echo "   Actual: $actual"
        fi
    # 期待値が数値の場合（完全一致チェック）
    else
        if [ "$actual" == "$expected" ]; then
            echo -e "${GREEN}[PASS]${NC} (Got: $actual)"
        else
            echo -e "${RED}[FAIL]${NC}"
            echo "   Expected: $expected"
            echo "   Actual:   $actual"
        fi
    fi
}
# --- 1. 正常系 (正しく計算されるべきもの) ---
echo -e "\n[Normal Cases]"
test_case "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
test_case "7 7 * 7 -" "42"
test_case "1 2 * 2 / 2 * 2 4 - +" "0"
test_case "3 4+2* 7 -" "7"
# --- 2. 異常系: 不正な文法 (数字が並びすぎる、最後が数字など) ---
echo -e "\n[Invalid Grammar Cases]"
test_case "1 2 3 + " "Error"       # 数字が余る
test_case "1 2 + 3" "Error"       # 最後が数字で終わる
test_case "10 1 +" "Error"         # 二桁の数字
test_case "1 2 + +" "Error"       # 演算子が多すぎる

# --- 3. 異常系: 不正な文字・記号 ---
echo -e "\n[Invalid Characters]"
test_case "(1 + 1)" "Error"       # 括弧
test_case "1 2 a +" "Error"       # アルファベット
test_case "1 2 %" "Error"        # 未対応の演算子
test_case "" "Error"              # 空文字

# --- 4. 異常系: スタック・算術エラー ---
echo -e "\n[Arithmetic & Stack Errors]"
test_case "1 0 /" "Error"        # ゼロ除算
test_case "1 + " "Error"         # 数字が足りない
test_case "1 2 + +" "Error"       # 演算子が多すぎる

echo -e "\n[Overflow & Underflow Cases]"
test_case "8  8  8  8  8  8  8  8  8  8    *  *  *  *  *  *  *  *  *" "1073741824"       # 
test_case "8  8  8  8  8  8  8  8  8  8  2 *  *  *  *  *  *  *  *  *  *" "Error" # INTオーバーフロー
test_case "8  8  8  8  8  8  8  8  8  8  2 1 2 - * *  *  *  *  *  *  *  *  *  *" "-2147483648" # INT_MIN
test_case "8  8  8  8  8  8  8  8  8  8  2 2 1 2 - * *  *  *  *  *  *  *  *  *  * * " "Error" # INTアンダーフロー



echo -e "\n--- Test Completed ---"