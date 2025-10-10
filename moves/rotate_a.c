/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:26:12 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:04:56 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief ra - rotate stack A upwards (first becomes last).
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [2, 1, 3]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack A.
 */
void	rotate_a(t_stack *stack_a)
{
	t_node	*head_a;

	if (stack_a->size < 2)
		return ;
	head_a = delete_first_node(stack_a);
	insert_node_in_tail(stack_a, head_a);
	write(1, "ra\n", 3);
}
