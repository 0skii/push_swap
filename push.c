#include "push_swap.h"

static void     push(head *src, head *dest)
{
    t_list  *x;

    if (src->first)
    {
        x = src->first;
        x->next = dest->first;
        dest->first = x;
        if (src->size > 1)
            src->first = src->first->next;
        else
            src->first = NULL;
    }
}

void    pa(head *stack_a, head *stack_b)
{
    push(stack_b, stack_a);
    printf("pa\n");
}

void    pb(head *stack_a, head *stack_b)
{
    push(stack_a, stack_b);
    printf("pb\n");
}
