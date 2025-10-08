/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:37:39 by radandri          #+#    #+#             */
/*   Updated: 2025/10/08 02:48:05 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_printf/ft_printf.h"
# include <limits.h>

/**
 * @struct s_node
 * @brief Represents a node in a doubly linked stack used in push_swap.
 *
 * Each node stores the original integer value, its compressed index
 * (rank in sorted order), and additional attributes to compute the
 * optimal moves between two stacks (stack A and B).
 *
 * Example usage:
 * @code
 * t_node *n = malloc(sizeof(t_node));
 * n->data = 42;        // raw value
 * n->index = 3;        // 4th smallest element
 * n->pos = 0;          // top of the stack
 * n->target_pos = 2;   // must be placed at position 2 in stack A
 * n->cost_a = 1;       // one rotation needed on stack A
 * n->cost_b = -2;      // two reverse rotations on stack B
 * @endcode
 */
typedef struct s_dlklist
{
	int data;               /**< Valeur brute */
	int index;              /**< Index dans la pile (position courante) */
	int rank;                /**< Rang normalisé (position triée), rank compris ente 0 et size-1 */
	int target_pos;         /**< Target position in the other stack */
	int cost_a;             /**< Rotation cost on stack A */
	int cost_b;             /**< Rotation cost on stack B */
	struct s_dlklist *next; /**< Pointer to the next node */
	struct s_dlklist *prev; /**< Pointer to the previous node */
}			t_node;

typedef struct s_doubly_linked_list
{
	t_node	*sentinel;
	int		size;
	t_node	*min;
	t_node	*max;
	t_node	*median;
}			t_stack;

	typedef struct s_pair
	{
		int data;
		int rank;
	} t_pair;

// linked list
void		printList(t_stack *s);
void		initList(t_stack *s);
t_stack		*create_stack(void);
void		updateStack(t_stack *s);
t_node		*insertInTail_checked(t_stack *s, int data);
t_node		*insertInHead(t_stack *stack, int data);
t_node		*deleteFirst(t_stack *s);
t_node		*deleteLast(t_stack* s);
void		insertNodeInHead(t_stack *stack, t_node *node);
void		insertNodeInTail(t_stack *s, t_node *node);
void		deleteNode(t_stack *s, t_node* node);
void		freeList(t_stack *s);
t_node *searchNode(t_stack* s, int x);

// parsing
int			is_valid_token(char *s);
int			has_duplicates(long *arr, int size);
t_stack		*parse_numbers_to_stack(char *str);
char		*ft_join_args(int argc, char *argv[]);
char		*ft_string_sanitize(char *args);

// utils
int			is_space(char c);
long		ft_atol(const char *str);
void		free_split(char **split);
void		swapFirst2(t_stack *stack);
void 		normalize_node_values(t_stack *s);

// k-sort
void    pushToBKsort(t_stack *a, t_stack *b);
void 	pushBackToA(t_stack *a, t_stack *b);

// move a
void		swap_a(t_stack *stack_a);

void		push_a(t_stack *stack_a, t_stack *stack_b);

void		rotate_a(t_stack *stack_a);

void		reverse_rotate_a(t_stack *stack_a);

// move b
void		swap_b(t_stack *stack_b);

void		push_b(t_stack *stack_a, t_stack *stack_b);

void		rotate_b(t_stack *stack_b);

// move a et b
void		reverse_rotate_b(t_stack *stack_b);

void		swap_both_a_b(t_stack *stack_a, t_stack *stack_b);

void		rotate_both_a_b(t_stack *stack_a, t_stack *stack_b);

void		reverse_rotate_both_a_b(t_stack *stack_a, t_stack *stack_b);
#endif