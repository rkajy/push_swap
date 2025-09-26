/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:33:02 by radandri          #+#    #+#             */
/*   Updated: 2025/09/27 00:46:36 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void printList(t_stack *s)
{
    ft_printf("list size = %d\n", s->size);
    t_node* current = s->sentinel->next;
    while (current != s->sentinel)
    {
        ft_printf("[pos %d]-> = %d\n", current->index, current->data);
        current = current->next;
    }
    ft_printf("\n");
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

void deleteLast(t_stack* s){
    if(s->size == 0)
        return ;
    t_node* lastNode = s->sentinel->prev;
    lastNode->prev->next = s->sentinel;
    s->sentinel->prev = lastNode->prev;
    lastNode->prev = NULL;
    lastNode->next = NULL;
    free(lastNode);
    s->size--;
    updateIndexes(s);
}

int main()
{

    t_stack list;
    initList(&list);

    insertInTail(&list, 1);
    insertInTail(&list, 2);
    insertInTail(&list, 3);

    ft_printf("Before deletion:\n");
    printList(&list);

    deleteLast(&list);

    ft_printf("After deletion:\n");
    printList(&list);

    insertInHead(&list, 9); //ajoute en tete de liste en position 0
    insertInHead(&list, 0); //ajoute en tete de list en position 0
    insertInHead(&list, -89);
    insertInTail(&list, 66); // ajoute en queue de list, en derniere position
    printList(&list);
    return 0;
}