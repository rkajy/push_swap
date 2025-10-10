/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:47:41 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:00:53 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief ss - sa and sb at the same time.
 *
 * Example:
 * Before:        After:
 * A: [3,2,1]     A: [2,3,1]
 * B: [9,7,5]     B: [7,9,5]
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void	swap_both_a_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_first2_nodes(stack_a);
	swap_first2_nodes(stack_b);
	write(1, "ss\n", 3);
}
