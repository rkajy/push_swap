/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertIntInHead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:27:11 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:15:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*insert_int_in_head(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = stack->sentinel->next;
	new_node->prev = stack->sentinel;
	stack->sentinel->next->prev = new_node;
	stack->sentinel->next = new_node;
	stack->size++;
	update_list(stack);
	return (new_node);
}
