#!/bin/bash
# test_ra.bash - unit tests for ra (rotate a)

# Rebuild clean
make -C .. fclean > /dev/null
make -C .. > /dev/null

# Compile a dedicated test binary (minimal main for RA)
cc -Wall -Werror -Wextra \
  ../push_swap_list.o ../push_swap_utils.o ../push_swap_move_a.o \
  ../push_swap_parsing.o ../libft_printf/libftprintf.a \
  test_ra.c -o test_ra

BINARY="./test_ra"

# Define test cases
declare -a tests=(
  ""              # empty stack
  "42"            # 1 element
  "1 2"           # 2 elements
  "3 2 1"         # 3 elements
  "-1 -2 -3"      # negatives
  "1 2 3 4 5"     # long stack
)

declare -a expected=(
  ""
  "[42]"
  "[2,1]"
  "[2,1,3]"
  "[-2,-3,-1]"
  "[2,3,4,5,1]"
)

echo "Running ra tests..."
for i in "${!tests[@]}"; do
  echo "Test $((i+1)): ${tests[$i]}"
  output=$($BINARY ${tests[$i]})
  if [[ "$output" == "${expected[$i]}" ]]; then
    echo "✅ Passed"
  else
    echo "❌ Failed"
    echo "   Got:      $output"
    echo "   Expected: ${expected[$i]}"
  fi
  echo
done

# Cleanup
make -C .. fclean > /dev/null
rm -f $BINARY
