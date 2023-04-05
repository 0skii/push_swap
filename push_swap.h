/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:21 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/04/04 11:43:30 by ozerbib-         ###   ########.fr       */
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

/*Main Structure*/
typedef struct t_list
{
	long int		content;
	struct t_list	*next;
}					t_list;

/*Control Structure*/
typedef struct t_head
{
	t_list				*first;
	long long int		size;
}						t_head;

/*Converter*/
void		atoi_add(char *str, t_head *stack_a);
/*List Utils*/
t_head		*new_nb(t_head *list, int nb);
void		print_list(t_head *list);
t_list		*last_pos(t_head *list);
t_list		*before_last_pos(t_head *list);
int			free_this(t_head *list, int torf);
void		check_double(t_head *list);
int			check_sort(t_head *list);
void		mini_sort(t_head *list);
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