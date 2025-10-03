/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/10/03 03:53:44 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief sa - swap the first 2 elements of stack A.
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [2, 3, 1]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack A.
 */
void swap_a(t_stack *stack_a)
{
    swapFirst2(stack_a);
    write(1, "sa\n", 3);
}

/**
 * @brief pa - push top element of stack B onto stack A.
 *
 * Example:
 * Before:        After:
 * A: [3, 2]      A: [5, 3, 2]
 * B: [5, 1]      B: [1]
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void push_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *head_b = deleteFirst(stack_b);
    insertNodeInHead(stack_a, head_b);
    write(1, "pa\n", 3);
}

/**
 * @brief ra - rotate stack A upwards (first becomes last).
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [2, 1, 3]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack A.
 */
void rotate_a(t_stack *stack_a)
{
    if(stack_a->size < 2)
        return;
        
    t_node *head_a = deleteFirst(stack_a);
    insertNodeInTail(stack_a, head_a);
    write(1, "ra\n", 3);
}

/**
 * @brief rra - reverse rotate stack A (last becomes first).
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [1, 3, 2]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack A.
 */
void reverse_rotate_a(t_stack *stack_a)
{
    (void)stack_a;
    write(1, "rra\n", 4);
}
