################################################################################
#                                     CONFIG                                   #
################################################################################
NAME     := push_swap
CC       := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      ft_printf/sources/ft_printf.c \
                          ft_printf/sources/ft_putlu.c \
                          ft_printf/sources/ft_putnbr_base.c \
                          ft_printf/sources/ft_putchar.c \
                          ft_printf/sources/ft_putuint.c \
                          ft_printf/sources/ft_putstr.c \
                          ft_printf/sources/ft_putptr.c \
                          sources/sort3.c \
                          sources/rotate.c \
                          sources/ft_atoi_add.c \
                          sources/push.c \
                          sources/rev_rotate.c \
                          sources/sort5.c \
                          sources/clean.c \
                          sources/swap.c \
                          sources/call_algo.c
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation of $(RED)$(NAME) $(GREEN)...${CLR_RMV}"
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)Good job! $(RED)$(NAME) $(GREEN)created ✔️"

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

joke:		all
			@echo "$(BLUE) Why do Java programmers have to wear glasses? Because they do not C sharp.$(CLR_RMV)"

parrot:		all
			@curl parrot.live

.PHONY:		all clean fclean re
