#include "push_swap.h"

t_list  *find_min(t_head *list)
{
    t_list      *x;
    t_list      *min_node;

    min_node = list->first;
    x = list->first->next;
    while (x)
    {
        if (x->content < min_node->content)
            min_node = x;
        x = x->next;        
    }
    return (min_node);
}

long int list_size(t_list *node)
{
    int     i;

    i = 0;
    while (node->next)
    {
        node = node->next;
        i++;
    }
    return (i);
}

int r_or_rr(t_head *list)
{
    if (list->size / 2 > list_size(find_min(list)))
        return (1);
    else
        return (0);
}

void    node_move(t_head *list, t_list *node, int bora)
{
    if (bora)
    {
        while(list->first->content != node->content)
            rra(list);
    }
    else if (!bora)
    {
        while (list->first->content != node->content)
            ra(list);
    }
}

void    mini_sort5(t_head *stack_a, t_head *stack_b)
{
    node_move(stack_a, find_min(stack_a), r_or_rr(stack_a));
    pb(stack_a, stack_b);
    node_move(stack_a, find_min(stack_a), r_or_rr(stack_a));
    pb(stack_a, stack_b);
    mini_sort3(stack_a);
    pa(stack_b, stack_a);
    pa(stack_b, stack_a);
}
