/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapFirst2Nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:33:02 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:03:48 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

/**
 * Swap two adjacent nodes n1 and n2 in a doubly linked list.
 * Precondition: n1->next == n2
 */
static void	swap_adjacent_nodes(t_node *n1, t_node *n2)
{
	t_node	*next;
	t_node	*prev;

	if (!n1 || !n2 || n1->next != n2)
		return ;
	prev = n1->prev;
	next = n2->next;
	n2->next = n1;
	n2->prev = prev;
	n1->prev = n2;
	n1->next = next;
	prev->next = n2;
	next->prev = n1;
	n1->index++;
	n1->index--;
}

void	swap_first2_nodes(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (stack->size == 0 || stack->size == 1)
		return ;
	first_node = stack->sentinel->next;
	second_node = stack->sentinel->next->next;
	swap_adjacent_nodes(first_node, second_node);
}
