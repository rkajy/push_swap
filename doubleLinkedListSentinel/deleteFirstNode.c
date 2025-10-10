/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteFirstNode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:31:48 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:04:55 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*delete_first_node(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size == 0)
		return (NULL);
	first = s->sentinel->next;
	second = first->next;
	s->sentinel->next = second;
	second->prev = s->sentinel;
	s->size--;
	first->next = NULL;
	first->prev = NULL;
	update_list(s);
	return (first);
}
