#include "../includes/push_swap.h"

void    whatever_the_fuck(t_head *stack_a, t_head *stack_b)
{
    long int    i;

    i = 1;
    i += list_size(stack_a->first);
    if (i == 3)
        mini_sort3_pt1(stack_a);
    else if (i == 5)
        mini_sort5(stack_a, stack_b);
}