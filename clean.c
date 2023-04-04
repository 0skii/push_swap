#include "push_swap.h"

/*The free_this function frees the memory allocated for each node
of my list. Either from an error or after every task was done successfully.*/
int free_this(head *list, int torf)
{
    t_list  *x;

    x = list->first;
    while(x)
    {
        list->first = x->next;
        free(x);
        x = list->first;
    }
    if (!torf)
        write(1, "Error\n", 7);
    else if (torf)
        write(1, "Memory Freed\n", 14);
    exit(torf);
}