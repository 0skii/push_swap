/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:27:49 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/13 17:00:08 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*I realized there are only five possible cases for three random numbers 
being put into stack_a. My goal is to make sure I sort them from smallest 
to largest in no more than two actions. The way I determine which actions 
I use depends on the position of the top number, middle number, and bottom
number. I divided my function in two possible cases. Wether the top number
is larger the the middle one or the opposit. I then go deeper in the
possibilities and make the moves necessary for every possible order.*/
void	mini_sort3(t_head *list)
{
	t_list	*x;
	t_list	*x2;

	if (!list)
		return ;
	x = list->first;
	x2 = x->next;
	if (x->content > x2->content)
	{
		if (freaknorm(list) == 1)
			ra(list);
		else if (x->content < last_pos(list)->content)
			sa(list);
		else
		{
			sa(list);
			rra(list);
		}
	}
	else if (x->content < x2->content)
	{
		if (x->content > last_pos(list)->content)
			rra(list);
		else if (freaknorm(list) == 2)
		{
			sa(list);
			ra(list);
		}
	}
}

/*I called this function freaknorm to stay polite. Our school's norm does 
not accept long lines of code. Hence this almost useless function.
Thanks norminette!*/
int	freaknorm(t_head *list)
{
	t_list	*x;
	t_list	*x2;
	int		i;

	x = list->first;
	x2 = x->next;
	i = 0;
	if (x->content > last_pos(list)->content)
	{
		if (x2->content < last_pos(list)->content)
		{
			i = 1;
			return (i);
		}
	}
	i = 0;
	if (x->content < last_pos(list)->content)
	{
		if (x2->content > last_pos(list)->content)
		{
			i = 2;
			return (i);
		}
	}
	return (0);
}
