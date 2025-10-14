/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:37:39 by radandri          #+#    #+#             */
/*   Updated: 2025/10/14 01:04:47 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "doubleLinkedListSentinel/linkedList.h"
# include "libft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_pair
{
	int	data;
	int	rank;
}		t_pair;

// parsing
int		is_valid_token(char *s);
t_stack	*parse_numbers_to_stack(char *str);
char	*ft_join_args(int argc, char *argv[]);
char	*ft_string_sanitize(char *args);

// utils
int		is_space(char c);
long	ft_atol(const char *str);
void	free_split(char **split);
void	swap_first2_nodes(t_stack *stack);
void	normalize_node_values(t_stack *s);
void	free_list(t_stack *s);

void	sort_3(t_stack *s);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

// k-sort
void	push_to_b_k_sort(t_stack *a, t_stack *b);
void	push_back_to_a(t_stack *a, t_stack *b);

// radix
void	radix_sort(t_stack *a, t_stack *b);

// move a
void	swap_a(t_stack *stack_a);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	reverse_rotate_a(t_stack *stack_a);

// move b
void	swap_b(t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_b(t_stack *stack_b);

// move a et b
void	reverse_rotate_b(t_stack *stack_b);
void	swap_both_a_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_both_a_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_both_a_b(t_stack *stack_a, t_stack *stack_b);
#endif