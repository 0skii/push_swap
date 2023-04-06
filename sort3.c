#include "push_swap.h"

void    mini_sort3(t_head *list)
{
    t_list  *x;
    t_list  *x2;

    if (!list)
        return ;
    x = list->first;
    x2 = x->next;
    if (x->content > x2->content)
    {
        if (x->content > last_pos(list)->content && x2->content < last_pos(list)->content)
            ra(list);
        else if (x->content < last_pos(list)->content)
            sa(list);
        else
        {
            sa(list);
            rra(list);
        }
    }
    else if (x->content < x2->content)
    {
        if (x->content > last_pos(list)->content)
            rra(list);
        else if (x->content < last_pos(list)->content && x2->content > last_pos(list)->content)
        {
            sa(list);
            ra(list);
        }
    }
    if (check_sort(list))
        return ;
}
