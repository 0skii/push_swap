#include "push_swap.h"

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
