/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/10/02 01:09:03 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack *stack_a)
{
    swapFirst2(stack_a);
    write(1, "sa\n", 3);
}

void push_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *head_b = deleteFirst(stack_b);
    insertNodeInHead(stack_a, head_b);
    write(1, "pa\n", 3);
}

void rotate_a(t_stack *stack_a)
{
    if(stack_a->size < 2)
        return;
        
    t_node *head_a = deleteFirst(stack_a);
    insertNodeInTail(stack_a, head_a);
    write(1, "ra\n", 3);
}

/**
 * Reverse rotates stack_a.
 * Moves last element to top, shifting others down by one.
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [1, 3, 2]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack to reverse rotate.
 */
void reverse_rotate_a(t_stack *stack_a)
{
    (void)stack_a;
    write(1, "rra\n", 4);
}
