/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:10 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/15 11:47:14 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*The free_this function frees the memory allocated for each node
of my list. Either from an error or after every task was done successfully.*/
/*int	free_this(t_head *stack_a, int torf)
{
	t_list	*x;
	t_list	*x2;

	x = stack_a->first;
	x2 = stack_a->first->next;
	while (x2)
	{
		free(x);
		x = x2;
		x2 = x->next;
	}
	free(x);
	if (torf == 1)
		ft_printf("Error\n");
	else if (torf == 2)
		ft_printf("Memory freed\n");
	exit(torf);
}*/

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
void	check_double(t_head *list)
{
	t_list	*x;
	t_list	*x2;

	if (!(list->first))
		return ;
	x = list->first;
	x2 = list->first->next;
	while (x->next)
	{
		while (x2)
		{
			if (x->content == x2->content)
				ult_free(list->first);
			x2 = x2->next;
		}
		x = x->next;
		x2 = x->next;
	}
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
