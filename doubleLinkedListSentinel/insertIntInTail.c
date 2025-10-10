/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertIntInTail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:24:11 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 07:29:25 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*insert_int_in_tail(t_stack *s, int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = -1;
	node->rank = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = s->sentinel;
	node->prev = s->sentinel->prev;
	s->sentinel->prev->next = node;
	s->sentinel->prev = node;
	s->size++;
	update_list(s);
	return (node);
}
