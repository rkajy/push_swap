/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 01:18:38 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:51:54 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_index(t_stack *a)
{
	t_node	*cur;
	int		max;

	cur = a->sentinel->next;
	max = cur->rank;
	while (cur != a->sentinel)
	{
		if (cur->rank > max)
			max = cur->rank;
		cur = cur->next;
	}
	return (max);
}

int	find_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = find_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	top_rank(t_stack *a)
{
	if (a->size == 0)
		return (-1);
	return (a->sentinel->next->rank);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	num;

	max_bits = find_max_bits(a);
	size = a->size;
	for (int i = 0; i < max_bits; i++)
	{
		for (int j = 0; j < size; j++)
		{
			num = top_rank(a);
			if (((num >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
		}
		while (b->size > 0)
			push_a(a, b);
	}
}

