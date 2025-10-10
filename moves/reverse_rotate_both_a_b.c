/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both_a_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:56:11 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:04:25 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void	reverse_rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*last_a;
	t_node	*last_b;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	last_a = delete_last_node(stack_a);
	insert_node_in_head(stack_a, last_a);
	last_b = delete_last_node(stack_b);
	insert_node_in_head(stack_b, last_b);
	write(1, "rrr\n", 4);
}
