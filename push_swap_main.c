/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 03:15:15 by radandri          #+#    #+#             */
/*   Updated: 2025/10/15 02:30:02 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char *argv[])
{
	char	*args;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	args = ft_join_args(argc, argv);
	if (!args)
		return (write(2, "Error\n", 6), 1);
	a = parse_numbers_to_stack(args);
	if (!a)
		return (free(args), write(2, "Error\n", 6), 1);
	if (is_sorted_stack(a))
		return (free_list(a), free(args), 0);
	b = create_list();
	if (!b)
		return (free_list(a), free(args), write(2, "Error\n", 6), 1);
	normalize_node_values(a);
	solve(a, b);
	free_list(a);
	free_list(b);
	free(args);
	return (0);
}
