/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:35:50 by radandri          #+#    #+#             */
/*   Updated: 2025/10/10 00:22:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i++]);
	}
	free(split);
}

void	free_list(t_stack *s)
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

/**
 * Checks if the given string token is valid according to specific criteria.
 *

	* A valid token is a non-empty string representing a signed or unsigned integer,
 * with an optional '+' or '-' at the beginning, followed by digits only.
 *
 * Example:
 *   is_valid_token("42")      -> 1
 *   is_valid_token("-123")    -> 1
 *   is_valid_token("+0")      -> 1
 *   is_valid_token("abc")     -> 0
 *   is_valid_token("")        -> 0
 *   is_valid_token("+")       -> 0
 *
 * @param s Pointer to the string token to validate.
 * @return 1 if the token is valid, 0 otherwise.
 */
int	is_valid_token(char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (!s[i + 1])
			return (0);
		i++;
	}
	if (s[i] == '0' && s[i + 1])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
