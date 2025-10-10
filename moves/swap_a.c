/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:47:21 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:00:33 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief sa - swap the first 2 elements of stack A.
 *
 * Example:
 * Before:        After:
 * A: [3, 2, 1]   A: [2, 3, 1]
 * B: []          B: []
 *
 * @param stack_a Pointer to stack A.
 */
void	swap_a(t_stack *stack_a)
{
	swap_first2_nodes(stack_a);
	write(1, "sa\n", 3);
}
