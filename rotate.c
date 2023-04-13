/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:53 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 15:37:31 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The rotate move takes the first node and puts
it at the bottom of the list, making the former second position
now first.*/
static void	rotate(t_head *list)
{
	t_list	*x;

	if (list && list->size > 1)
	{
		x = list->first;
		list->first = list->first->next;
		x->next = NULL;
		last_pos(list)->next = x;
	}
}

void	ra(t_head *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_head *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_head *stack_a, t_head *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
