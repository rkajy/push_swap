/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:33:02 by radandri          #+#    #+#             */
/*   Updated: 2025/09/30 07:21:29 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print the stack in a single line like [1,2,3]
 */
void printList(t_stack *s)
{
    t_node *curr = s->sentinel->next;
    int first = 1;

    ft_printf("[");
    while (curr != s->sentinel)
    {
        if (!first)
            ft_printf(",");
        ft_printf("%d", curr->data);
        first = 0;
        curr = curr->next;
    }
    ft_printf("]\n");
}


void initList(t_stack *s)
{
    s->sentinel = malloc(sizeof(t_node));
    if(!s->sentinel)
    {
        if(!s)
            free(s);
        return;
    }
    s->sentinel->data = -1;
    s->sentinel->index = -1;
    s->sentinel->next = s->sentinel;
    s->sentinel->prev = s->sentinel;
    s->size = 0;
}

void    updateIndexes(t_stack *s)
{
    int i =0;
    t_node *cur = s->sentinel->next;
    while (cur != s->sentinel)
    {
        cur->index = i++;
        cur = cur->next;
    }
}

int search(t_stack* s, int x)
{
    t_node *current;

    current = s->sentinel->next;
    while (current != s->sentinel)
    {
        if(current->data == x)
            return current->index;
        current = current->next;
    }
    return (-1);
}

t_node* insertInTail(t_stack *s, int data)
{
    t_node *node = malloc(sizeof(t_node));
    if(!node)
        return (NULL);
    node->data = data;
    node->next = s->sentinel;
    node->prev = s->sentinel->prev;
    s->sentinel->prev->next = node;
    s->sentinel->prev = node;
    s->size++;
    updateIndexes(s);
    return node;
}

t_node* insertInTail_checked(t_stack *s, int data)
{
    if(search(s, data) != -1)
        return (NULL);
    return (insertInTail(s, data));
}

t_node* insertInHead(t_stack *stack, int data)
{
    t_node *newNode = (t_node*) malloc(sizeof(t_node));
    if(!newNode)
        return (NULL);
    newNode->data = data;
    newNode->next = stack->sentinel->next;
    newNode->prev = stack->sentinel;
    stack->sentinel->next->prev = newNode;
    stack->sentinel->next = newNode;
    stack->size++;
    updateIndexes(stack);
    return newNode;
}

/**
 * Swap two adjacent nodes n1 and n2 in a doubly linked list.
 * Precondition: n1->next == n2
 */
static void swap_adjacent_nodes(t_node *n1, t_node *n2)
{
    if(!n1 || !n2 || n1->next != n2)
        return;
    t_node *next;
    t_node *prev;

    prev = n1->prev;
    next = n2->next;

    n2->next = n1;
    n2->prev = prev;

    n1->prev = n2;
    n1->next = next;

    prev->next = n2;
    next->prev = n1;

    n1->pos++;
    n1->pos--;
}

void swapFirst2(t_stack *stack)
{
    t_node *firstNode;
    t_node *secondNode;

    if(stack->size == 0 || stack->size == 1)
        return;
    firstNode = stack->sentinel->next;
    secondNode = stack->sentinel->next->next;
    swap_adjacent_nodes(firstNode, secondNode);
}

// void deleteLast(t_stack* s){
//     if(s->size == 0)
//         return ;
//     t_node* lastNode = s->sentinel->prev;
//     lastNode->prev->next = s->sentinel;
//     s->sentinel->prev = lastNode->prev;
//     lastNode->prev = NULL;
//     lastNode->next = NULL;
//     free(lastNode);
//     s->size--;
//     updateIndexes(s);
// }



// int main(int argc, char *argv[])
// {
//     (void)argc;
//     (void)argv;
//     // ft_printf("long = %ld\n", ft_atol(argv[1]));
//     printf("long = %ld\n", ft_atol(argv[1]));
//     return 0;
// }



// int main(int argc, char *argv[])
// {
//     ft_argv_sanitize(argc, argv);
//     char *input = " 42 \t+1337 \t    -89  0    7         ";

//     t_stack *list = parse_numbers_to_stack(input);

//     ft_printf("Liste générée :\n");
//     printList(list);

//     return 0;
// }

// int main()
// {

//     t_stack list;
//     initList(&list);

//     insertInTail(&list, 1);
//     insertInTail(&list, 2);
//     insertInTail(&list, 3);

//     ft_printf("Before deletion:\n");
//     printList(&list);

//     deleteLast(&list);

//     ft_printf("After deletion:\n");
//     printList(&list);

//     insertInHead(&list, 9); //ajoute en tete de liste en position 0
//     insertInHead(&list, 0); //ajoute en tete de list en position 0
//     insertInHead(&list, -89);
//     insertInTail(&list, 66); // ajoute en queue de list, en derniere position
//     printList(&list);
//     return 0;
// }