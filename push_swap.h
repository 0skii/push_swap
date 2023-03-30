#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

typedef struct t_list
{
	long int		content;
	struct	t_list	*next;
}					t_list;

typedef struct head
{
	t_list				*first;
	long long int		size;
} 						head;

void		ft_atoi_add(char *str);
head  		*new_nb(head *list, int nb);
void    	print_list(head *list);
t_list		*last_pos(head *list);
void		sa(head *stack_a);
void		sb(head *stack_b);
void    	pa(head *stack_a, head *stack_b);
void    	pb(head *stack_a, head *stack_b);

#endif