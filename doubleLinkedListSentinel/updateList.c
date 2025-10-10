/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updateList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:37:42 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:17:25 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*find_median_node(t_stack *stack)
{
	t_node	*cur;
	int		target_index;

	target_index = stack->size / 2;
	if (!stack || stack->size == 0)
		return (NULL);
	cur = stack->sentinel->next;
	while (target_index-- && cur != stack->sentinel)
		cur = cur->next;
	return (cur);
}

void	update_list(t_stack *s)
{
	int		i;
	t_node	*cur;

	if (!s || !s->sentinel || s->size == 0)
		return ;
	cur = s->sentinel->next;
	s->min = cur;
	s->max = cur;
	i = 0;
	while (cur != s->sentinel)
	{
		cur->index = i++;
		if (cur->rank < s->min->rank)
			s->min = cur;
		if (cur->rank > s->max->rank)
			s->max = cur;
		cur = cur->next;
	}
}
