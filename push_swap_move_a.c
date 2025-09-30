/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/09/30 07:17:39 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack *stack_a)
{
    (void) stack_a;
    swapFirst2(stack_a);
    write(1, "sa\n", 3);
}

void push_a(t_stack *stack_a)
{
    (void)stack_a;
    write(1, "pa\n", 3);
}

void rotate_a(t_stack *stack_a)
{
    (void)stack_a;
    write(1, "ra\n", 3);
}

void reverse_rotate_a(t_stack *stack_a)
{
    (void)stack_a;
    write(1, "rra\n", 4);
}
