/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchIndexVal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:39:08 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:11:12 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

int	search_index_val(t_stack *s, int x)
{
	t_node	*current;

	current = s->sentinel->next;
	while (current != s->sentinel)
	{
		if (current->data == x)
			return (current->index);
		current = current->next;
	}
	return (-1);
}
