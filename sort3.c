#include "push_swap.h"

/*I realized there are only five possible cases for three random numbers 
being put into stack_a. My goal is to make sure I sort them from smallest 
to largest in no more than two actions. The way I determine which actions 
I use depends on the position of the top number, middle number, and bottom
number. I divided my function in two possible cases. Wether the top number
is larger the the middle one or the opposit. I then go deeper in the
possibilities and make the moves necessary for every possible order.*/
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
}
