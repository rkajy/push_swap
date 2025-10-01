#include "../push_swap.h"

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