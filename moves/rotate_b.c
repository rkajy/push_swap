/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:39:35 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:05:11 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief rb - rotate stack B upwards (first becomes last).
 *
 * Example:
 * Before:        After:
 * A: []          A: []
 * B: [9, 7, 5]   B: [7, 5, 9]
 *
 * @param stack_b Pointer to stack B.
 */
void	rotate_b(t_stack *stack_b)
{
	t_node	*head_b;

	if (stack_b->size < 2)
		return ;
	head_b = delete_first_node(stack_b);
	insert_node_in_tail(stack_b, head_b);
	write(1, "rb\n", 3);
}
