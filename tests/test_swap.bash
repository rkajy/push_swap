#!/bin/bash
# test_swap.bash - unit tests for swap

# Rebuild clean
make -C .. fclean > /dev/null
make -C .. > /dev/null

# Compile a dedicated test binary (minimal main for RA)
cc -Wall -Werror -Wextra \
  ../push_swap_list.o ../push_swap_utils.o ../push_swap_move_a.o \
  ../push_swap_parsing.o ../libft_printf/libftprintf.a \
  test_swap.c -o test_swap

BINARY="./test_swap"

declare -a tests=(
  ""                 # empty stack
  "42"               # 1 element
  "1 2"              # 2 elements
  "3 2 1"            # 3 elements
  "-1 -2 -3"         # negatives
  "5 10 15 20"       # long stack
  "1 2 3 4"          # already sorted ascending
  "4 3 2 1"          # already sorted descending
  "1 1 2"            # with duplicates
)

declare -a expected=(
  ""                 # nothing happens
  "[42]"             # unchanged
  "[2,1]"            # swapped
  "[2,3,1]"          # only first 2 swapped
  "[-2,-1,-3]"       # only first 2 swapped
  "[10,5,15,20]"     # swap first 2 only
  "[2,1,3,4]"        # ascending → swap first 2
  "[3,4,2,1]"        # descending → swap first 2
  "Error"          # duplicates → handled
)

echo "Running swap tests..."
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
