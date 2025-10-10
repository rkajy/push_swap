/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printList.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:30:12 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:11:29 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"
#include "../libft_printf/ft_printf.h"

/**
 * @brief Print the stack in a single line like [1,2,3]
 */
void	print_list(t_stack *s)
{
	t_node	*curr;
	int		first;

	curr = s->sentinel->next;
	first = 1;
	ft_printf("[");
	while (curr != s->sentinel)
	{
		if (!first)
			ft_printf(",");
		ft_printf("%d (rank = %d)", curr->data, curr->rank);
		first = 0;
		curr = curr->next;
	}
	ft_printf("]\n");
}
