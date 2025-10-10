/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertNodeInHead.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:27:44 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:16:35 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

void	insert_node_in_head(t_stack *stack, t_node *node)
{
	t_node	*old_head;

	if (!node)
		return ;
	old_head = stack->sentinel->next;
	stack->sentinel->next = node;
	node->prev = stack->sentinel;
	node->next = old_head;
	old_head->prev = node;
	stack->size++;
	update_list(stack);
}
