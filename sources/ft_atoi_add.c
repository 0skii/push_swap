/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:57 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/15 11:49:48 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*atoi_add is my void function to convert characters into integers.
First, skipping thru all tabs and spaces, recognizing if
a sign is present then making the conversion to integers.*/
void	atoi_add(char *str, t_head *stack_a)
{
	long long int	res;
	long long int	sign;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = (*str != '-') - (*str == '-');
	if ((*str == '+' || *str == '-'))
		str++;
	if (!*str)
	{
		ult_free(stack_a->first);
	}
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + *str++ - 48;
	res *= sign;
	new_nb(stack_a, res);
	if ((*str >= 9 && *str <= 13) || *str == 32)
		atoi_add(str, stack_a);
	else if (*str)
		ult_free(stack_a->first);
	return ;
}

/*new_nb is the function I use to add nodes into my linked list.
I also increment my size variable here to keep track of the size of my list.*/
t_head	*new_nb(t_head *list, int nb)
{
	t_list			*data;
	t_list			*x;

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
	return (list);
}

/*last_pos is used to find the last node of my list. It is useful 
for later operations on the list.*/
t_list	*last_pos(t_head *list)
{
	t_list	*x;

	if (!list)
		return (NULL);
	x = list->first;
	while (x && x->next)
		x = x->next;
	return (x);
}

/*print_list has the same concept as last_pos but while I'm going
thru the list I print each node.*/
void	print_list(t_head *list)
{
	t_list	*x;

	x = list->first;
	while (x)
	{
		ft_printf("%i -> ", x->content);
		x = x->next;
	}
	write(1, "NULL\n", 6);
}

/*Driver code*/
int	main(int argc, char **argv)
{
	int				i;
	static t_head	stack_a;
	static t_head	stack_b;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		atoi_add(argv[i], &stack_a);
		i++;
	}
	check_double(&stack_a);
	if (check_sort(&stack_a))
		return (ult_free(stack_a.first));
	//printf("List Size: %f\n", stack_a.size);
	whatever_the_fuck(&stack_a, &stack_b);
	//print_list(&stack_a);
	/*if (check_sort(&stack_a))
		ft_printf("Sorted\n");*/
	ult_free(stack_a.first);
}
