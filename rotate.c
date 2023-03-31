#include "push_swap.h"

/*The rotate move takes the first node and puts
it at the bottom of the list, making the former second position
now first.*/
static void     rotate(head *list)
{
    t_list  *x;

    if (list && list->size > 1)
    {
        x = list->first;
        list->first = list->first->next;
        x->next = NULL;
        last_pos(list)->next = x;
    }
}

void    ra(head *stack_a)
{
    rotate(stack_a);
    printf("ra\n");
}

void    rb(head *stack_b)
{
    rotate(stack_b);
    printf("rb\n");
}

void    rr(head *stack_a, head *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}