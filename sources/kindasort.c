/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindasort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:47:01 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/25 16:25:14 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*The first step of my algortihm from 5 to 500 arguments is calculating the
average of values inside the list.*/
int	average(t_head *list)
{
	t_list		*x;
	long int	sum;

	x = list->first;
	sum = 0;
	while (x)
	{
		sum += x->content;
		x = x->next;
	}
	sum = sum / list->size;
	return (sum);
}

/*Then, whichever node on top of the list at that moment I compare to the
actual average. If its lower I push it to the other stack( bigger I just
rotate). I calculate the average again after that and pushing everytime its
under. Over and over until I have five nodes remaining in the original
stack. Then I just run my sort5 algorithm inside it.*/
void	average_push(t_head *stack_a, t_head *stack_b)
{
	t_list	*x;

	while (stack_a->size > 5)
	{
		x = stack_a->first;
		if (x->content < average(stack_a))
		{
			node_move(stack_a, x, r_or_rr(stack_a));
			pb(stack_a, stack_b);
			if (stack_b->size > 1 && x->content < average(stack_b))
				rb(stack_b);
		}
		else if (x->content >= average(stack_a))
			ra(stack_a);
	}
	mini_sort5(stack_a, stack_b);
}
