/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:37:39 by radandri          #+#    #+#             */
/*   Updated: 2025/09/25 23:17:37 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft_printf/ft_printf.h"

typedef struct s_dlklist
{
	int			data;
	struct s_dlklist	*next;
	struct s_dlklist	*prev;
	int	index;
}					t_node;

typedef struct s_doubly_linked_list{
    t_node *sentinel;
    int size;
} t_stack;

#endif