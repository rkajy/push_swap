/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/10/02 00:02:19 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_b(t_stack *stack_b)
{
    swapFirst2(stack_b);
    write(1, "sb\n", 3);
}

void push_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *head_a = deleteFirst(stack_a);
    insertNodeInHead(stack_b, head_a);
    write(1, "pb\n", 3);
}

void rotate_b(t_stack *stack_b)
{
    if(stack_b->size < 2)
        return;

    t_node *head_b = deleteFirst(stack_b);
    insertNodeInTail(stack_b, head_b);
    write(1, "rb\n", 3);
}