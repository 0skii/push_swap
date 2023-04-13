/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:47 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/12 22:08:09 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The reverse rotate move sends the last node to the first position
of that same list, making the former first position now second.*/
static void	rev_rotate(t_head *list)
{
	t_list	*x;

	x = last_pos(list);
	last_pos(list)->next = list->first;
	while (list->first->next != x)
		list->first = list->first->next;
	list->first->next = NULL;
	list->first = x;
}

void	rra(t_head *stack_a)
{
	rev_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_head *stack_b)
{
	rev_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_head *stack_a, t_head *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	printf("rrr\n");
}
