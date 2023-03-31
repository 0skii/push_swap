#include "push_swap.h"

/*The reverse rotate move sends the last node to the first position
of that same list, making the former first position now second.*/
t_list	*before_last_pos(head *list)
{
	  t_list  *x;

    if (!list)
		return (NULL);
    x = list->first;
	while (x && x->next->next == NULL)
		x = x->next;
	return (x);
}

static void rev_rotate(head *list)
{
    t_list  *x;

    x = last_pos(list);
    last_pos(list)->next = list->first;
    while (list->first->next != x)
		  list->first = list->first->next;
    list->first->next = NULL;
    list->first = x;
}

void    rra(head *stack_a)
{
    rev_rotate(stack_a);
    printf("rra\n");
}

void    rrb(head *stack_b)
{
    rev_rotate(stack_b);
    printf("rrb\n");
}

void    rrr(head *stack_a, head *stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    printf("rrr\n");
}