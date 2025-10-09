#include "push_swap.h"

int find_max_index(t_stack *a)
{
    t_node *cur = a->sentinel->next;
    int max = cur->rank;
    while (cur != a->sentinel)
    {
        if (cur->rank > max)
            max = cur->rank;
        cur = cur->next;
    }
    return max;
}

int find_max_bits(t_stack *a)
{
    int max = find_max_index(a);
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

int top_rank(t_stack *a)
{
    if (a->size == 0)
        return -1;
    return a->sentinel->next->rank;
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits = find_max_bits(a);
    int size = a->size;

    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num = top_rank(a);
            if (((num >> i) & 1) == 1)
                rotate_a(a);
            else
                push_b(a, b);
        }
        while (b->size > 0)
            push_a(a, b);
    }
}

int main(int argc, char* argv[])
{
    char *args;
    t_stack *a;
    t_stack *b;

    if(argc == 1 || (argc == 2 && !argv[1][0]))
        return 0;

    args = ft_join_args(argc, argv);
    if (!args)
        return (ft_printf("Error\n"), 1);

    a = parse_numbers_to_stack(args);
    if(!a)
        return (ft_printf("Error\n"), 1);

    b = create_stack();
    normalize_node_values(a); // remplit le champ rank

    radix_sort(a, b);

    freeList(a);
    freeList(b);
    free(args);
    return 0;
}