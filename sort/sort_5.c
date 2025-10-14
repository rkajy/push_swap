/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:00:22 by radandri          #+#    #+#             */
/*   Updated: 2025/10/14 03:43:08 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_5(t_stack *a, t_stack *b)
{
	update_list(a);
	while (a->sentinel->next->index != a->min->index)
	{
		if (a->min->index <= a->size / 2)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	push_b(a, b);
	update_list(a);
	while (a->sentinel->next->index != a->min->index)
	{
		if (a->min->index <= a->size / 2)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
	push_a(a, b);
}
