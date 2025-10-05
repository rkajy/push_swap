#!/usr/bin/env bash
# test_push.bash - unit tests for push operations (pa/pb)

make -C .. fclean > /dev/null
make -C .. > /dev/null

cc -Wall -Werror -Wextra \
  ../push_swap_list.o ../push_swap_utils.o ../push_swap_move_push.o \
  ../push_swap_parsing.o ../libft_printf/libftprintf.a \
  test_push.c -o test_push

BINARY="./test_push"

# Test cases
declare -a tests_A=(
  ""           # A vide, B vide
  "1"          # A=1 , B vide
  ""           # A vide, B=2
  "1 2"        # A=1 2 , B=3
  "1 2 3"      # A=1 2 3 , B=4 5
  "-1 -2"      # A négatif
)

declare -a tests_B=(
  ""           # A vide, B vide
  ""           # A=1 , B vide
  "2"          # A vide, B=2
  "3"          # A=1 2 , B=3
  "4 5"        # A=1 2 3 , B=4 5
  "-5"         # A=-1 -2 , B=-5
)

declare -a expected_A=(
  "[]"         # rien
  "[]"         # A=1 → push vers B
  "[]"         # A vide → rien à push
  "[2]"        # A=[2]
  "[2,3]"      # A=[2,3]
  "[-2]"       # A=[-2]
)

declare -a expected_B=(
  "[]"         # rien
  "[1]"        # B=[1]
  "[2]"        # inchangé
  "[1,3]"      # B=[1,3]
  "[1,4,5]"    # B=[1,4,5]
  "[-1,-5]"    # B=[-1,-5]
)

echo "Running push tests..."
for i in "${!tests_A[@]}"; do
  echo "Test $((i+1)): A='${tests_A[$i]}' | B='${tests_B[$i]}'"
  
  # Appelle ton binaire test_push avec les deux piles
  output=$($BINARY "${tests_A[$i]}" "${tests_B[$i]}")
  
  # On suppose que printList affiche "A: [...]" puis "B: [...]"
  actual_A=$(echo "$output" | grep "A:" | cut -d':' -f2 | tr -d ' ')
  actual_B=$(echo "$output" | grep "B:" | cut -d':' -f2 | tr -d ' ')

  expA=${expected_A[$i]}
  expB=${expected_B[$i]}

  if [[ "$actual_A" == "$expA" && "$actual_B" == "$expB" ]]; then
    echo "✅ Passed"
  else
    echo "❌ Failed"
    echo "   Got A=$actual_A / B=$actual_B"
    echo "   Expected A=$expA / B=$expB"
  fi
  echo
done

make -C .. fclean > /dev/null
rm -f $BINARY
