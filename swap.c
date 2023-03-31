#include "push_swap.h"

/*The swap move swaps the first node and the second, taking
each others place subsequently.*/
static void    swap(head *list)
{
    t_list  *x;

    if (list && list->size > 1)
    {
        x = list->first;
        list->first = list->first->next;
        x->next = list->first->next;
        list->first->next = x;
    }
}

void    sa(head *stack_a)
{
    swap(stack_a);
    printf("sa\n");
}

void    sb(head *stack_b)
{
    swap(stack_b);
    printf("sb\n");
}

void    ss(head *stack_a, head *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}