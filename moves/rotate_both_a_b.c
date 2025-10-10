/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both_a_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:48:51 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:05:57 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief rr - ra and rb at the same time.
 *
 * Example:
 * Before:        After:
 * A: [3,2,1]     A: [2,1,3]
 * B: [9,7,5]     B: [7,5,9]
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void	rotate_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*head_a;
	t_node	*head_b;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	head_a = delete_first_node(stack_a);
	insert_node_in_tail(stack_a, head_a);
	head_b = delete_first_node(stack_b);
	insert_node_in_tail(stack_b, head_b);
	write(1, "rr\n", 3);
}
