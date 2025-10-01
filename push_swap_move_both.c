/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:56:11 by radandri          #+#    #+#             */
/*   Updated: 2025/10/02 01:09:11 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Reverse rotates stack B.
 *
 * Moves last element of stack B to top,
 * shifts all other elements down by one.
 * shifting all other elements down by one.
 *
 * Example:
 * Before:        After:
 * A: []          A: []
 * B: [7, 9, 5]   B: [5, 7, 9]
 *
 * @param stack_b Pointer to stack B to reverse rotate.
 */
void reverse_rotate_b(t_stack *stack_b)
{
    (void)stack_b;
    write(1, "rrb\n", 4);
}

void    swap_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    swapFirst2(stack_a);
    swapFirst2(stack_b);
    write(1, "ss\n", 3);
}

/**
 * @brief Rotates both stack_a and stack_b upwards by one position.
 *
 * This function performs a simultaneous rotation on both stacks,
 * moving the top element of each stack to the bottom.
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [2, 1, 3]
 * B: [7, 9, 5]   B: [9, 5, 7]
 *
 * @param stack_a Pointer to the first stack (stack_a) to be rotated.
 * @param stack_b Pointer to the second stack (stack_b) to be rotated.
 */
void rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    write(1, "rr\n", 3);
}

/**
 * @brief Performs a reverse rotation on both stack_a and stack_b.
 *
 * This function moves the last element of each stack to the top,
 * effectively rotating both stacks in reverse simultaneously.
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [1, 3, 2]
 * B: [7, 9, 5]   B: [5, 7, 9]
 *
 * @param stack_a Pointer to the first stack (t_stack).
 * @param stack_b Pointer to the second stack (t_stack).
 */
void reverse_rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_a;
    (void)stack_b;
    write(1, "rrr\n", 4);
}