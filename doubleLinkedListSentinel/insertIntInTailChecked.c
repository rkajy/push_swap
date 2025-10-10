/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertIntInTailChecked.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:25:43 by radandri          #+#    #+#             */
/*   Updated: 2025/10/09 23:09:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedList.h"

t_node	*insert_int_in_tail_checked(t_stack *s, int data)
{
	if (search_index_val(s, data) != -1)
		return (NULL);
	return (insert_int_in_tail(s, data));
}
