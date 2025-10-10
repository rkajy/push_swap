/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchNodeVal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:42:17 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:11:00 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*search_node_val(t_stack *s, int x)
{
	t_node	*current;

	current = s->sentinel->next;
	while (current != s->sentinel)
	{
		if (current->data == x)
			return (current);
		current = current->next;
	}
	return (NULL);
}
