#!/bin/bash
# push_swap_test_full.sh
# Test push_swap parsing with quotes, spaces, tabs, etc.

make fclean > /dev/null
make > /dev/null

BINARY="./push_swap"

# Test cases: argv style (quotes included for single string inputs)
declare -a tests=(
  "1 2 3"
  "\"1 2 3\""
  "\"  1   2 3  \""
  "+1 -2 3"
  "0 2147483647 -2147483648"
  "1 2 dog 3"
  "a"
  "1 2 3b"
  "--3"
  "++5"
  "1 3 58 9 3"
  "3 03"
  "54867543867438 3"
  "-2147483647765 4 5"
  "\" 1  2    3 \""
  "\" 1\t  2  3 \""
  ""
  " "
  "0"
  "000"
)

declare -a expected=(
  "[1,2,3]"
  "[1,2,3]"
  "[1,2,3]"
  "[1,-2,3]"
  "[0,2147483647,-2147483648]"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "Error"
  "[1,2,3]"
  "[1,2,3]"
  "Error"
  "Error"
  "[0]"
  "Error"
)

for i in "${!tests[@]}"; do
  echo "Test $((i+1)): ${tests[$i]}"
  # Use eval to expand quotes properly
  output=$(eval $BINARY ${tests[$i]})
  if [[ $output == "${expected[$i]}"* ]]; then
    echo "✅ Passed"
  else
    echo "❌ Failed"
    echo "   Got: $output"
    echo "   Expected: ${expected[$i]}"
  fi
  echo
done

make fclean > /dev/null