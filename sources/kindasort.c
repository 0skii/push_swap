/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kindasort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:47:01 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/19 16:45:45 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int average(t_head *list)
{
	t_list      *x;
    long int    sum;

    x = list->first;
    sum = 0;
    while (x)
    {
        sum += x->content;
        x = x->next;
    }
    sum = sum / list->size;
    //ft_printf("%i\n", sum);
	return (sum);
}

void	average_push(t_head *stack_a, t_head *stack_b)
{
    t_list  *x;

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
