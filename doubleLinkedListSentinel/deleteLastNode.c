/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteLastNode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:31:13 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:18:03 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*delete_last_node(t_stack *s)
{
	t_node	*last_node;
	t_node	*prevlast_node;

	if (s->size == 0)
		return (NULL);
	last_node = s->sentinel->prev;
	prevlast_node = last_node->prev;
	prevlast_node->next = s->sentinel;
	s->sentinel->prev = prevlast_node;
	last_node->prev = NULL;
	last_node->next = NULL;
	s->size--;
	update_list(s);
	return (last_node);
}
