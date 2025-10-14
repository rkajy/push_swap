/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:00:19 by radandri          #+#    #+#             */
/*   Updated: 2025/10/14 01:32:26 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_4(t_stack *a, t_stack *b)
{
	t_node	*head;

	update_list(a);
	head = a->sentinel;
	while (head->index != a->min->index)
	{
		if (a->min->index <= a->size / 2)
			rotate_a(a);
		else if (a->min->index > a->size / 2)
			reverse_rotate_a(a);
	}
	push_b(a, b);
	sort_3(a);
	push_a(a, b);
}
