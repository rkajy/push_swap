/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:02:41 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_b;

	head_b = delete_first_node(stack_b);
	insert_node_in_head(stack_a, head_b);
	write(1, "pa\n", 3);
}
