/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:56:11 by radandri          #+#    #+#             */
/*   Updated: 2025/10/04 00:41:34 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief rrb - reverse rotate stack B (last becomes first).
 *
 * Moves last element of stack B to top,
 * shifts all other elements down by one.
 * shifting all other elements down by one.
 *
 * Example:
 * Before:        After:
 * A: []          A: []
 * B: [9, 7, 5]   B: [5, 9, 7]
 *
 * @param stack_b Pointer to stack B.
 */
void reverse_rotate_b(t_stack *stack_b)
{
    if(stack_b->size < 2)
        return;
    t_node* last = deleteLast(stack_b);
    insertNodeInHead(stack_b, last);
    write(1, "rrb\n", 4);
}

/**
 * @brief ss - sa and sb at the same time.
 *
 * Example:
 * Before:        After:
 * A: [3,2,1]     A: [2,3,1]
 * B: [9,7,5]     B: [7,9,5]
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void    swap_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    swapFirst2(stack_a);
    swapFirst2(stack_b);
    write(1, "ss\n", 3);
}

/**
 * @brief rr - ra and rb at the same time.
 *
 * Example:
 * Before:        After:
 * A: [3,2,1]     A: [2,1,3]
 * B: [9,7,5]     B: [7,5,9]
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *head_a;
    t_node *head_b;

    if(stack_a->size < 2 || stack_b->size <2)
        return;
        
    head_a = deleteFirst(stack_a);
    insertNodeInTail(stack_a, head_a);

    head_b = deleteFirst(stack_b);
    insertNodeInTail(stack_b, head_b);

    write(1, "rr\n", 3);
}

/**
 * @brief rrr - rra and rrb at the same time.
 *
 * This function moves the last element of each stack to the top,
 * effectively rotating both stacks in reverse simultaneously.
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [1, 3, 2]
 * B: [9, 7, 5]   B: [5, 9, 7]
 *
 * @param stack_a Pointer to the first stack (t_stack).
 * @param stack_b Pointer to the second stack (t_stack).
 */
void reverse_rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node* last_a;
    t_node* last_b;

    if(stack_a->size < 2 || stack_b->size < 2)
        return;
    last_a = deleteLast(stack_a);
    insertNodeInHead(stack_a, last_a);
    last_b = deleteLast(stack_b);
    insertNodeInHead(stack_b, last_b);
    write(1, "rrr\n", 4);
}