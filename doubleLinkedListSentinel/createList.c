/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:33:30 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:12:59 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_stack	*create_list(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->sentinel = malloc(sizeof(t_node));
	if (!s->sentinel)
	{
		free(s);
		return (NULL);
	}
	s->sentinel->data = 0;
	s->sentinel->index = -1;
	s->sentinel->next = s->sentinel;
	s->sentinel->prev = s->sentinel;
	s->size = 0;
	s->min = NULL;
	s->max = NULL;
	s->median = NULL;
	return (s);
}
