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
	struct	t_list	*next;
}					t_list;

/*Control Structure*/
typedef struct head
{
	t_list				*first;
	long long int		size;
} 						head;

/*Converter*/
void		atoi_add(char *str, head *stack_a);
/*List Utils*/
head  		*new_nb(head *list, int nb);
void    	print_list(head *list);
t_list		*last_pos(head *list);
t_list		*before_last_pos(head *list);
/*List Moves*/
void		sa(head *stack_a);
void		sb(head *stack_b);
void    	ss(head *stack_a, head *stack_b);
void    	pa(head *stack_b, head *stack_a);
void    	pb(head *stack_a, head *stack_b);
void    	ra(head *stack_a);
void    	rb(head *stack_b);
void    	rr(head *stack_a, head *stack_b);
void    	rra(head *stack_a);
void		rrb(head *stack_b);
void    	rrr(head *stack_a, head *stack_b);

#endif