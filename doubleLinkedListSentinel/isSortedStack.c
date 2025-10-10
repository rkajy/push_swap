/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isSortedStack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:28:23 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:11:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

int	is_sorted_stack(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->sentinel)
		return (0);
	if (stack->size <= 1)
		return (1);
	curr = stack->sentinel->next;
	while (curr != stack->sentinel)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}
