#include "push_swap.h"

void reverse_rotate_b(t_stack *stack_b)
{
    (void)stack_b;
    write(1, "rrb\n", 4);
}

void    swap_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    write(1, "ss\n", 3);
}

void rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    write(1, "rr\n", 3);
}

void reverse_rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    write(1, "rrr\n", 4);
}