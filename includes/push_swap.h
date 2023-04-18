/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:21 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/18 11:49:24 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include "../ft_printf/includes/ft_printf.h"

/*List Structure*/
typedef struct t_list
{
	long int		content;
	struct t_list	*next;
}					t_list;

/*Control Structure*/
typedef struct t_head
{
	t_list		*first;
	float		size;
}				t_head;

/*Converter/Parsing*/
void		atoi_add(char *str, t_head *stack_a);
/*List Utils*/
t_head		*new_nb(t_head *list, int nb);
void		print_list(t_head *list);
t_list		*last_pos(t_head *list);
int			ult_free(t_list *node);
void		check_double(t_head *list);
int			check_sort(t_head *list);
int			average(t_head *list);
t_list		*find_min(t_head *list);
int			r_or_rr(t_head *list);
long int	node_to_bottom(t_list *node);
void		node_move(t_head *list, t_list *node, int bora);
int			freaknorm(t_head *list);
t_list		*phone_a_friend(t_head *stack_a, t_list *b);
void		go_to_friend(t_head *stack_a, t_head *stack_b);
/*Algos*/
void		mini_sort3_pt1(t_head *list);
void		mini_sort3_pt2(t_head *list);
void		mini_sort5(t_head *stack_a, t_head *stack_b);
void		average_push(t_head *stack_a, t_head *stack_b);
void		whatever_the_fuck(t_head *stack_a, t_head *stack_b);
/*List Moves*/
void		sa(t_head *stack_a);
void		sb(t_head *stack_b);
void		ss(t_head *stack_a, t_head *stack_b);
void		pa(t_head *stack_b, t_head *stack_a);
void		pb(t_head *stack_a, t_head *stack_b);
void		ra(t_head *stack_a);
void		rb(t_head *stack_b);
void		rr(t_head *stack_a, t_head *stack_b);
void		rra(t_head *stack_a);
void		rrb(t_head *stack_b);
void		rrr(t_head *stack_a, t_head *stack_b);

#endif
