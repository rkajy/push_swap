/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initList.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:31:18 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:06:47 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

void	init_list(t_stack *s)
{
	s->sentinel = malloc(sizeof(t_node));
	if (!s->sentinel)
		return ;
	s->sentinel->data = -1;
	s->sentinel->index = -1;
	s->sentinel->next = s->sentinel;
	s->sentinel->prev = s->sentinel;
	s->size = 0;
	s->max = NULL;
	s->min = NULL;
	s->median = NULL;
}
