/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/09/30 07:17:45 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_b(t_stack *stack_b)
{
    (void) stack_b;
    swapFirst2(stack_b);
    write(1, "sb\n", 3);
}

void push_b(t_stack *stack_b)
{
    (void)stack_b;
    write(1, "pb\n", 3);
}

void rotate_b(t_stack *stack_b)
{
    (void)stack_b;
    write(1, "rb\n", 3);
}