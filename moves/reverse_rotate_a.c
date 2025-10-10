/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:25:40 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:03:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief rra - reverse rotate stack A (last becomes first).
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [1, 3, 2]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack A.
 */
void	reverse_rotate_a(t_stack *stack_a)
{
	t_node	*last;

	if (stack_a->size < 2)
		return ;
	last = delete_last_node(stack_a);
	insert_node_in_head(stack_a, last);
	write(1, "rra\n", 4);
}
