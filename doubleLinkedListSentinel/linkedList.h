/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 05:08:06 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 07:19:21 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct s_dlklist
{
	int					data;
	int					index;
	int					rank;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_dlklist	*next;
	struct s_dlklist	*prev;
}						t_node;

typedef struct s_doubly_linked_list
{
	t_node				*sentinel;
	int					size;
	t_node				*min;
	t_node				*max;
	t_node				*median;
}						t_stack;

t_stack					*create_list(void);
t_node					*delete_first_node(t_stack *s);
t_node					*delete_last_node(t_stack *s);
void					delete_node(t_stack *s, t_node *node);
void					init_list(t_stack *s);
t_node					*insert_int_in_head(t_stack *stack, int data);
t_node					*insert_int_in_tail(t_stack *s, int data);
t_node					*insert_int_in_tail_checked(t_stack *s, int data);
void					insert_node_in_head(t_stack *stack, t_node *node);
void					insert_node_in_tail(t_stack *s, t_node *node);
int						is_sorted_stack(t_stack *stack);
void					print_list(t_stack *s);
int						search_index_val(t_stack *s, int x);
t_node					*search_node_val(t_stack *s, int x);
void					swap_first2_nodes(t_stack *stack);
void					update_list(t_stack *s);

#endif