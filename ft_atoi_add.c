#include "push_swap.h"

void	ft_atoi_add(char *str)
{
	long long int	        res;
	long long int           sign;
    static head             stack_a;
    static head             stack_b;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
    sign = (*str != '-') - (*str == '-');
	if ((*str == '+' || *str == '-'))
		str++;
    if (!*str)
        printf("Error\n");
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + *str++ - 48;
    res *= sign;
    new_nb(&stack_a, res);
    if ((*str >= 9 && *str <= 13) || *str == 32)
        ft_atoi_add(str);
    else if (*str)
        printf("Error\n");
    else
    {
        new_nb(&stack_b, 7);
        new_nb(&stack_b, 8);
        new_nb(&stack_b, 9);
        print_list(&stack_b);
        print_list(&stack_a);
        //pb(&stack_a, &stack_b);
        print_list(&stack_a);
        print_list(&stack_b);
    }
    return ;
}

head  *new_nb(head *list, int nb)
{
    t_list                  *data;
    t_list                  *x;

    data = (t_list *)malloc(sizeof(*data));
    data->content = nb;
    data->next = NULL;
    if (!list->first)
        list->first = data;
    else
    {
        x = last_pos(list);
        x->next = data;
    }
    list->size++;
    //printf("size: %lli", size);
    return (list);
}

t_list	*last_pos(head *list)
{
	t_list  *x;

    if (!list)
		return (NULL);
    x = list->first;
	while (x && x->next)
		x = x->next;
	return (x);
}

void    print_list(head *list)
{
    t_list  *x;

    x = list->first;
    while (x)
    {
        printf("%ld -> ", x->content);
        x = x->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    int         i;

    i = 1;
    while (i < argc)
    {
        ft_atoi_add(argv[i]);
        i++;
    }
}
