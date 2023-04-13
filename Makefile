# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 15:42:28 by ozerbib-          #+#    #+#              #
#    Updated: 2023/04/13 16:12:08 by ozerbib-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := push_swap
CC       := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS     :=      sort5.c \
                    rev_rotate.c \
                    swap.c \
                    rotate.c \
                    ft_atoi_add.c \
                    ft_printf/source/ft_putptr.c \
                    ft_printf/source/ft_putnbr_base.c \
                    ft_printf/source/ft_putlu.c \
                    ft_printf/source/ft_putchar.c \
                    ft_printf/source/ft_putuint.c \
                    ft_printf/source/ft_putstr.c \
                    ft_printf/source/ft_printf.c \
                    sort3.c \
                    push.c \
                    clean.c \
                          
OBJS     := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
