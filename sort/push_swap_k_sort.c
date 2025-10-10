/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_k_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:56:50 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 01:18:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_sqrt(int nb)
{
	int	root;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	root = 1;
	while (root <= nb / 2)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}

static int	get_decision_median(int size)
{
	double	k;

	k = 1.3 * ft_sqrt((double)size);
	if (k < 1)
		k = 1;
	return ((int)k);
}

void	push_to_b_k_sort(t_stack *a, t_stack *b)
{
	int	median;

	if (!a || !b || a->size == 0)
		return ;
	median = get_decision_median(a->size);
	while (a->size > 0)
	{
		if (a->sentinel->next->rank <= b->size)
		{
			push_b(a, b);
			rotate_b(b);
		}
		else if (a->sentinel->next->rank <= b->size + median)
		{
			push_b(a, b);
		}
		else
			rotate_a(a);
	}
}

static int	find_max_rank_pos(t_stack *b)
{
	t_node	*curr;
	int		max_rank;
	int		pos;
	int		i;

	curr = b->sentinel->next;
	max_rank = curr->rank;
	pos = 0;
	i = 0;
	while (curr != b->sentinel)
	{
		if (curr->rank > max_rank)
		{
			max_rank = curr->rank;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = find_max_rank_pos(b);
		if (pos <= b->size / 2)
			while (pos-- > 0)
				rotate_b(b);
		else
			while (pos++ < b->size)
				reverse_rotate_b(b);
		push_a(a, b);
	}
}
