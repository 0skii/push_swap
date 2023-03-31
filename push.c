#include "push_swap.h"

/*Here the push move sends the first node of the src list
to the first position of the dest list. The former first node of the dest
list now becoming second. I also update the size variable everytime
I call a push. This is the only move between the two lists, all the other
moves are internal.*/
static void     push(head *src, head *dest)
{
    t_list  *x;

    if (src->first)
    {
        x = src->first;
        if (src->size > 1)
            src->first = src->first->next;
        else
            src->first = NULL;
        x->next = dest->first;
        dest->first = x;
    }
}

void    pa(head *stack_b, head *stack_a)
{
    push(stack_b, stack_a);
    stack_b->size--;
    stack_a->size++;
    printf("pa\n");
}

void    pb(head *stack_a, head *stack_b)
{
    push(stack_a, stack_b);
    stack_a->size--;
    stack_b->size++;
    printf("pb\n");
}
