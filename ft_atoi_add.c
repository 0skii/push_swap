/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:57 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/04 11:44:09 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("Error\n");
	}
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + *str++ - 48;
	res *= sign;
	new_nb(stack_a, res);
	if ((*str >= 9 && *str <= 13) || *str == 32)
		atoi_add(str, stack_a);
	else if (*str)
		printf("Error\n");
	return ;
}

/*new_nb is the function I use to add nodes into my linked list.
I also increment my size variable here to keep track of the size of my list.*/
t_head	*new_nb(t_head *list, int nb)
{
	t_list	*data;
	t_list	*x;

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
		printf("%ld -> ", x->content);
		x = x->next;
	}
	printf("NULL\n");
}

/*Driver code*/
int	main(int argc, char **argv)
{
	int				i;
	static t_head	stack_a;
	static t_head	stack_b;

	i = 1;
	while (i < argc)
	{
		atoi_add(argv[i], &stack_a);
		i++;
	}
	/*new_nb(&stack_b, 6);
	new_nb(&stack_b, 7);
	new_nb(&stack_b, 8);
	new_nb(&stack_b, 9);
	new_nb(&stack_b, 10);*/
	print_list(&stack_a);
	print_list(&stack_b);
	printf("Size(A):%lli\n", stack_a.size);
	printf("Size(B):%lli\n", stack_b.size);
	mini_sort(&stack_a);
	//check_double(&stack_a);
	print_list(&stack_a);
	if (check_sort(&stack_a))
		printf("success\n");
	//free_this(&stack_a, 1);
	//free_this(&stack_b, 1);
}
