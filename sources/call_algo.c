/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:54:41 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/20 01:55:11 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*This beautiful funtion calculates the number of elements inside a list
(node_to_bottom(t_list *node)) and determines which algorithm is best.*/
void	whatever_the_fuck(t_head *stack_a, t_head *stack_b)
{
	long int	i;

	i = stack_a->size;
	if (i > 1 && i <= 3)
		mini_sort3_pt1(stack_a);
	else if (i > 3 && i <= 5)
		mini_sort5(stack_a, stack_b);
	else if (i > 5)
	{
		average_push(stack_a, stack_b);
		good_nodes_to_top(stack_b, stack_a);
		min_to_top(stack_a);
	}
}
