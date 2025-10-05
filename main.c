/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:19:36 by radandri          #+#    #+#             */
/*   Updated: 2025/10/05 19:55:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int argc, char* argv[])
{
    char *args;
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if(argc == 1 || (argc == 2 && !argv[1][0]))
        return 0;
    (void)b;
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
    while (a->size != 3)
    {
        push_b(a,b);
    }
    ft_printf("a:\n");
    printList(a);
    ft_printf("b:\n");
    printList(b);
    return (0);
}
