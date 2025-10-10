/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertIntInTail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:24:11 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:08:12 by radandri         ###   ########.fr       */
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
	node->next = s->sentinel;
	node->prev = s->sentinel->prev;
	s->sentinel->prev->next = node;
	s->sentinel->prev = node;
	s->size++;
	update_list(s);
	return (node);
}
