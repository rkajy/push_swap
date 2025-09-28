/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:38:10 by radandri          #+#    #+#             */
/*   Updated: 2025/09/28 05:53:52 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
    char *args;
    t_stack *a;

    args= ft_join_args(argc, argv);
    if (!args)
    {
        ft_printf("Error\n");
        return (1);
    }
    
    a = parse_numbers_to_stack(args);
    if(!a)
    {
        ft_printf("Error\n");
        return (1);        
    }
    printList(a);
    return (0);
}
