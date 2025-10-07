/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:35:50 by radandri          #+#    #+#             */
/*   Updated: 2025/10/07 23:27:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the given character is a whitespace character.
 *
 * Returns non-zero if `c` is a whitespace character: tab (9), line feed (10),
 * vertical tab (11), form feed (12), carriage return (13), or space (32).
 * Otherwise, returns 0.
 *
 * @param c The character to check.
 * @return Non-zero if `c` is a whitespace character, 0 otherwise.
 */
int	is_space(char c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

long	ft_atol(const char *str)
{
	long	res;
	int		i;
	int		sign;
	int		temp;

	res = 0;
	i = 0;
	sign = 1;
	temp = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		// printf("current = %c, val =%d\n", str[i], (str[i]) - '0');
		temp = (str[i] - '0');
		res += temp;
		res *= 10;
		i++;
	}
	res /= 10;
	return (res * sign);
}

void	free_split(char **split)
{
	int i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i++]);
	}
	free(split);
}

void	freeList(t_stack *s)
{
	t_node	*curr;
	t_node	*next;

	if (!s || !s->sentinel)
		return ;
	curr = s->sentinel->next;
	while (curr != s->sentinel)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(s->sentinel);
	s->sentinel = NULL;
	s->size = 0;
	s->min = NULL;
	s->max = NULL;
	s->median = NULL;
}

// static t_node	*get_min_node(t_stack *s)
// {
// 	t_node	*curr;
// 	t_node	*min;

// 	curr = s->sentinel->next;
// 	min = curr;
// 	while (curr != s->sentinel)
// 	{
// 		if (curr->data < min->data)
// 			min = curr;
// 		curr = curr->next;
// 	}
// 	return (min);
// }

static int cmp_data(const void *a, const void *b)
{
	const t_pair *pa = (const t_pair *)a;
	const t_pair *pb = (const t_pair *)b;

	return (pa->data - pb->data);
}

void	normalize_node_values(t_stack *s)
{
	t_pair tab[s->size];
	t_node *curr;
	int i;
	t_pair temp;

	if(!s || !s->sentinel)
		return ;
	curr = s->sentinel->next;
	i = 0;
	temp.data = 0;
	while (curr != s->sentinel)
	{
		temp.data = curr->data;
		tab[i++] = temp;
		curr = curr->next;
	}
	qsort(tab, s->size, sizeof(t_pair), cmp_data);	
	i = 0;
	curr = NULL;
	while (i < s->size)
	{
		curr = searchNode(s, tab[i].data);
		if(curr)
			curr->rank = i++;
	}
}

