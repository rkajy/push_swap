#include "../push_swap.h"

int main(int argc, char* argv[])
{
    char *args;
    t_stack *stack_a;

    if(argc == 1)
        return 0;

    args= ft_join_args(argc, argv);
    if (!args)
    {
        ft_printf("Error\n");
        return (1);
    }
    
    stack_a = parse_numbers_to_stack(args);
    if(!stack_a)
    {
        ft_printf("Error\n");
        return (1);        
    }

    //if(stack_a->size < 2)
    //    return (0);
    if(stack_a->size >= 2){    
    t_node *head_a = deleteFirst(stack_a);
    insertNodeInTail(stack_a, head_a);
    }
    printList(stack_a);
    return (0);
}