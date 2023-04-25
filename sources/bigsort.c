/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:52:59 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/25 17:24:12 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*My phone_a_friend function takes the stack_a and a specific node as
arguments. Substracting that node to every stack_a node, finding the best
neighbour by updating everytime it finds a negative result larger than the
last one while still being smaller than 0.*/
int	*phone_a_friend(t_head *stack_a, t_list *b_node)
{
	int			min;
	int			diff;
	static int	pair[2];
	t_list		*x;

	x = stack_a->first;
	min = INT_MIN;
	while (x)
	{
		diff = b_node->content - x->content;
		if (diff > min && diff < 0)
		{
			min = diff;
			pair[0] = x->content;
			pair[1] = b_node->content;
		}
		x = x->next;
	}
	return (pair);
}

/*I use the check_cost function to count the number of moves it would be
necessarry to put the right node at the top of the list. Minding of
of its position (if it is located inside the first half I will count
from the top, if it is inside the second half I count from the bottom).*/
int	check_cost(t_head *stack_a, t_list *node, int *pair)
{
	int		i;
	int		j;
	t_list	*temp_a;

	i = 0;
	j = 0;
	temp_a = stack_a->first;
	while (temp_a && temp_a->content != pair[0] && ++i)
		temp_a = temp_a->next;
	if (i > (node_to_bottom(stack_a->first) / 2 + 1))
		i = node_to_bottom(stack_a->first) - i;
	while (node && node->content != pair[1] && ++j)
		node = node->next;
	if (j > (node_to_bottom(node) / 2 + 1))
		j = node_to_bottom(node) - j;
	return (i + j);
}

/*The bis function checks the best friend of each node inside the
stack_b and adds their cost to the ones of their best friend
inside the stack_a. Updates everytime it finds a cheaper pair to
move to the top of each stack.*/
int	*bis(t_head *stack_a, t_head *stack_b)
{
	static int	bis[2];
	int			*pair;
	int			min;
	int			temp;
	t_list		*temp_b;

	temp_b = stack_b->first;
	min = INT_MAX;
	while (temp_b)
	{
		pair = phone_a_friend(stack_a, temp_b);
		temp = check_cost(stack_a, temp_b, pair);
		if (temp < min)
		{
			min = temp;
			bis[0] = pair[0];
			bis[1] = pair[1];
			if (min == 0)
				break ;
		}
		temp_b = temp_b->next;
	}
	return (bis);
}

/*The sole purpose of the best_to_top function is to put the best
pair to the top of each stack, so that I can push them from stack_b
to stack_a.*/
void	best_to_top(t_head *stack_a, t_head *stack_b)
{
	int		best_pair[2];
	int		*tmp;

	while (stack_b->size >= 1)
	{
		tmp = bis(stack_a, stack_b);
		best_pair[0] = tmp[0];
		best_pair[1] = tmp[1];
		while (stack_a->first->content != best_pair[0])
			ra(stack_a);
		while (stack_b->first->content != best_pair[1])
			rot_rrot_b(stack_b, best_pair[1]);
		pa(stack_b, stack_a);
	}
}

/*I noticed that sometimes the cheapest node inside the stack_b could
be in the second half of the list, so instead of spending to many
moves just rotating I reverse rotate the list until the best pair
is at the top.*/
void	rot_rrot_b(t_head *stack_b, int node_cont)
{
	t_list	*x;

	x = stack_b->first;
	while (x->content != node_cont)
		x = x->next;
	if (stack_b->size / 2 > node_to_bottom(x))
		rrb(stack_b);
	else
		rb(stack_b);
}
