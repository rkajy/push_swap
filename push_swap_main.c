/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:38:10 by radandri          #+#    #+#             */
/*   Updated: 2025/10/11 15:57:08 by radandri         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	char	*args;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	args = ft_join_args(argc, argv);
	if (!args)
		return (ft_printf("Error\n"), 1);
	a = parse_numbers_to_stack(args);
	if (!a)
		return (ft_printf("Error\n"), 1);
	if (is_sorted_stack(a))
		return (0);
	b = create_list();
	normalize_node_values(a);
	radix_sort(a, b);
	free_list(a);
	free_list(b);
	free(args);
	return (0);
}
