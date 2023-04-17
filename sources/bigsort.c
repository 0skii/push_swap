/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:52:59 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/17 19:30:59 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*phone_a_friend(t_head *stack_a, t_head *stack_b)
{
	long int	b_node;
	t_list		*xa;
	t_list		*reta;
	int			min_diff;

	b_node = stack_b->first->content;
	xa = stack_a->first;
	min_diff = INT_MAX;
	while (xa)
	{
		if ((xa->content - b_node) > 0 && (xa->content - b_node) < min_diff)
		{
			min_diff = xa->content - b_node;
			reta = xa;
		}
		xa = xa->next;
	}
	ft_printf("%i\n", reta->content);
	return (reta);
}