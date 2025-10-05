ARG=$(seq -100 100 | shuf)
./push_swap $ARG | ./checker_linux $ARG
echo "Instructions:" $(./push_swap $ARG | wc -l)