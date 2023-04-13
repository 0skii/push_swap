/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:59 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 15:36:42 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The swap move swaps the first node and the second, taking
each others place subsequently.*/
static void	swap(t_head *list)
{
	t_list	*x;

	if (list && list->size > 1)
	{
		x = list->first;
		list->first = list->first->next;
		x->next = list->first->next;
		list->first->next = x;
	}
}

void	sa(t_head *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_head *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_head *stack_a, t_head *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
