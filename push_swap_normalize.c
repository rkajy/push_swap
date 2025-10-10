/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:55:43 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 07:14:01 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cmp_data(const void *a, const void *b)
{
	const t_pair	*pa = (const t_pair *)a;
	const t_pair	*pb = (const t_pair *)b;

	return (pa->data - pb->data);
}

void	normalize_node_values(t_stack *s)
{
	t_pair	*tab;
	t_node	*curr;
	int		i;

	if (!s || !s->sentinel)
		return ;
	tab = ft_calloc(sizeof(t_pair), s->size);
	if (!tab)
		return ;
	curr = s->sentinel->next;
	i = 0;
	while (curr != s->sentinel)
	{
		tab[i++].data = curr->data;
		curr = curr->next;
	}
	qsort(tab, s->size, sizeof(t_pair), cmp_data);
	i = 0;
	while (i < s->size)
	{
		curr = search_node_val(s, tab[i].data);
		if (curr)
			curr->rank = i++;
	}
	free(tab);
}
