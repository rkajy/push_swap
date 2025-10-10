/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:29:01 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:02:55 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;

	head_a = delete_first_node(stack_a);
	insert_node_in_head(stack_b, head_a);
	write(1, "pb\n", 3);
}
