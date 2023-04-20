/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:52:59 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/20 02:15:06 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*phone_a_friend(t_head *list, t_list *pnode)
{
	long int	node;
	t_list		*x;
	t_list		*ret;
	int			min_diff;

	node = pnode->content;
	x = list->first;
	min_diff = INT_MAX;
	ret = NULL;
	while (x)
	{
		if ((x->content - node) > 0 && (x->content - node) < min_diff)
		{
			min_diff = x->content - node;
			ret = x;
		}
		x = x->next;
	}
	if (!ret)
		ret = find_min(list);
	return (ret);
}

/*void	go_to_friend(t_head *stack_a, t_head *stack_b)
{
	t_list	*x;

	x = stack_b->first;
	while (x)
	{
		if (stack_a->size / 2 > node_to_bottom(phone_a_friend(stack_a, x)))
		{
			while (stack_a->first->content != \
			phone_a_friend(stack_a, x)->content)
				rra(stack_a);
		}
		else
		{
			while (stack_a->first->content != \
			phone_a_friend(stack_a, x)->content)
				ra(stack_a);
		}
		pa(stack_b, stack_a);
		x = stack_b->first;
	}
}*/

int	get_pos(t_head *list, t_list *node)
{
	int		i;

	node = list->first;
	i = 0;
	while (node && i < (list->size / 2))
	{
		i++;
		node = node->next;
	}
	while (node && i >= (list->size) / 2)
	{
		i--;
		node = node->next;
	}
	return (i);
}

t_list	*check_cost(t_head *stack_b, t_head *stack_a)
{
	t_list	*b_node;
	t_list	*a_node;
	t_list	*good_b_node;
	int		min;

	b_node = stack_b->first;
	min = INT_MAX;
	while (b_node)
	{
		a_node = phone_a_friend(stack_a, b_node);
		get_pos(stack_a, a_node);
		if (get_pos(stack_b, b_node) + get_pos(stack_a, a_node) < min)
		{
			min = get_pos(stack_b, b_node) + get_pos(stack_a, a_node);
			good_b_node = b_node;
		}
		b_node = b_node->next;
	}
	return (good_b_node);
}

int	check_half(t_head *list, t_list *node)
{
	if (list->size / 2 > node_to_bottom(node))
		return (1);
	else
		return (0);
}

void good_nodes_to_top(t_head *stack_b, t_head *stack_a)
{
	t_list 	*good_bnode;
	t_list	*good_anode;
	
	while (stack_b)
	{
		good_bnode = check_cost(stack_b, stack_a);
		while (good_bnode->content != stack_b->first->content)
		{
			if (check_half(stack_b, good_bnode))
				rrb(stack_b);
			else if (!check_half(stack_b, good_bnode))
				rb(stack_b);
		}
		good_anode = phone_a_friend(stack_b, good_anode);
		while (good_anode->content != stack_b->first->content)
		{
			if (check_half(stack_a, good_anode))
				rra(stack_a);
			else if (!check_half(stack_a, good_anode))
				ra(stack_a);
		}
		pa(stack_b, stack_a);
	}
}