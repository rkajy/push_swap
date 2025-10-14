/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:00:12 by radandri          #+#    #+#             */
/*   Updated: 2025/10/14 01:32:20 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *s)
{
	update_list(s);
	if (s->max->index == 0)
	{
		rotate_a(s);
	}
	else if (s->max->index == 1)
	{
		swap_a(s);
		rotate_a(s);
	}
	if (s->min->index == 1)
	{
		swap_a(s);
	}
	else if (s->min->index == 2)
	{
		reverse_rotate_a(s);
	}
}
