/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteNode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:30:34 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:06:26 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

void	delete_node(t_stack *s, t_node *node)
{
	if (!s || !s->sentinel || !node || node == s->sentinel)
		return ;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	s->size--;
	update_list(s);
}
