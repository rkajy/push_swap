/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/10/03 03:59:23 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief sb - swap the first 2 elements of stack B.
 *
 * Example:
 * Before:        After:
 * A: []          A: []
 * B: [9, 7, 5]   B: [7, 9, 5]
 *
 * @param stack_b Pointer to stack B.
 */
void swap_b(t_stack *stack_b)
{
    swapFirst2(stack_b);
    write(1, "sb\n", 3);
}

/**
 * @brief pb - push top element of stack A onto stack B.
 *
 * Example:
 * Before:        After:
 * A: [3, 2]      A: [2]
 * B: [5, 1]      B: [3, 5, 1]
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void push_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *head_a = deleteFirst(stack_a);
    insertNodeInHead(stack_b, head_a);
    write(1, "pb\n", 3);
}

/**
 * @brief rb - rotate stack B upwards (first becomes last).
 *
 * Example:
 * Before:        After:
 * A: []          A: []
 * B: [9, 7, 5]   B: [7, 5, 9]
 *
 * @param stack_b Pointer to stack B.
 */
void rotate_b(t_stack *stack_b)
{
    if(stack_b->size < 2)
        return;

    t_node *head_b = deleteFirst(stack_b);
    insertNodeInTail(stack_b, head_b);
    write(1, "rb\n", 3);
}