/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:47:04 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:04:04 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void	reverse_rotate_b(t_stack *stack_b)
{
	t_node	*last;

	if (stack_b->size < 2)
		return ;
	last = delete_last_node(stack_b);
	insert_node_in_head(stack_b, last);
	write(1, "rrb\n", 4);
}
