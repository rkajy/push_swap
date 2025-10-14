/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 03:15:15 by radandri          #+#    #+#             */
/*   Updated: 2025/10/14 03:15:42 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main_ksort(int argc, char *argv[])
// {
// 	char	*args;
// 	t_stack	*a;
// 	t_stack	*b;

// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (0);
// 	args = ft_join_args(argc, argv);
// 	if (!args)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	a = parse_numbers_to_stack(args);
// 	if (!a)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	b = create_list();
// 	normalize_node_values(a);
// 	push_to_b_k_sort(a, b);
// 	push_back_to_a(a, b);
// 	free_list(a);
// 	free_list(b);
// 	return (0);
// }

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
		return (0);
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	args = ft_join_args(argc, argv);
	if (!args)
		return (write(2, "Error\n", 6), 1);
	a = parse_numbers_to_stack(args);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	if (is_sorted_stack(a))
		return (0);
	b = create_list();
	normalize_node_values(a);
	solve(a, b);
	return (free_list(a), free_list(b), free(args), 0);
}
