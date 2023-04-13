/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:21:16 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 16:23:40 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find_min function goes through the list with the first element
as reference, it compares it too every other one and if it finds
a smaller one it updates the old one finding the smallest integer
inside the list.*/
t_list	*find_min(t_head *list)
{
	t_list	*x;
	t_list	*min_node;

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

/*I use the list_size function to count positions from the smallest
node (in the situation I use it) to the end of the list.*/
long int	list_size(t_list *node)
{
	int	i;

	i = 0;
	while (node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}

/*Once I know the position of the smallest node in the list,
I use r_or_rr function to find out if it is in the first half of
the list or in the second half. Returning 0 or 1 accordingly.*/
int	r_or_rr(t_head *list)
{
	if (list->size / 2 > list_size(find_min(list)))
		return (1);
	else
		return (0);
}

/*Now that I know in which half the node is in, I can decide whether to
make it rotate or reverse rotate so that I can save up on some moves.*/
void	node_move(t_head *list, t_list *node, int bora)
{
	if (bora)
	{
		while (list->first->content != node->content)
			rra(list);
	}
	else if (!bora)
	{
		while (list->first->content != node->content)
			ra(list);
	}
}

/*For the sorting of five numbers my logic is simple. Finding the two
smallest numbers in the list and pushing them to stack_b. Using my mini_sort3
to sort the stack_a then pushing back the other two numbers in the stack_a.*/
void	mini_sort5(t_head *stack_a, t_head *stack_b)
{
	node_move(stack_a, find_min(stack_a), r_or_rr(stack_a));
	pb(stack_a, stack_b);
	node_move(stack_a, find_min(stack_a), r_or_rr(stack_a));
	pb(stack_a, stack_b);
	mini_sort3_pt1(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
