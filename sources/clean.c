/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:10 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/25 16:18:16 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*The ult_free recursive function frees the memory allocated for each node
(last to first) of my list.*/
int	ult_free(t_list *node)
{
	if (node->next)
		ult_free(node->next);
	free(node);
	return (0);
}

/*The check_double function merely checks if there's any duplicate numbers
going into the list. If that is the case, I free everything then exit
using my free_this function above.*/
int	check_double(t_head *list)
{
	t_list	*x;
	t_list	*x2;

	if (!(list->first))
		return (0);
	x = list->first;
	x2 = list->first->next;
	while (x->next)
	{
		while (x2)
		{
			if (x->content == x2->content)
				return (1);
			x2 = x2->next;
		}
		x = x->next;
		x2 = x->next;
	}
	return (0);
}

/*I use the check_sort function to verify if my list has been sorted
correctly.*/
int	check_sort(t_head *list)
{
	t_list	*x;
	t_list	*x2;

	if (!(list->first))
		return (0);
	if (list->size == 1)
		return (0);
	x = list->first;
	x2 = list->first->next;
	while (x2)
	{
		if (x->content > x2->content)
			return (0);
		x = x->next;
		x2 = x2->next;
	}
	return (1);
}

/*My check_max function is a simple protection against a node value above
the int limits*/
int	check_max(t_head *list)
{
	t_list	*x;

	x = list->first;
	while (x)
	{
		if (x->content > INT_MAX || x->content < INT_MIN)
			return (1);
		x = x->next;
	}
	return (0);
}

/*Once I had run my big algorithms i noticed that sometimes the linked list
was sorted but not with the minimum value on top of the list. So I created
the min_to_top function.*/
void	min_to_top(t_head *stack_a)
{
	while (find_min(stack_a)->content != stack_a->first->content)
		ra(stack_a);
}
