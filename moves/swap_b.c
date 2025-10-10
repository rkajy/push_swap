/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:23:53 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:00:41 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief sb - swap the first 2 elements of stack B.
 *
 * Example:
 * Before:        After:
 * A: []          A: []
 * B: [9, 7, 5]   B: [7, 9, 5]
 *
 * @param stack_b Pointer to stack B.
 */
void	swap_b(t_stack *stack_b)
{
	swap_first2_nodes(stack_b);
	write(1, "sb\n", 3);
}
