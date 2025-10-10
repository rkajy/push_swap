/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertNodeInTail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:26:28 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:12:11 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

void	insert_node_in_tail(t_stack *s, t_node *node)
{
	t_node	*last;

	if (!node)
	{
		return ;
	}
	last = s->sentinel->prev;
	last->next = node;
	node->prev = last;
	node->next = s->sentinel;
	s->sentinel->prev = node;
	s->size++;
	update_list(s);
}
