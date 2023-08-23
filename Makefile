NAME	= push_swap
SRCS	= init.c \
		  init_utils.c \
		  chained_list.c \
		  ft_printf.c \
		  ft_printf_utils.c \
		  printf_stack_a.c \
		  actions.c \
		  actions_both.c \
		  sort.c \
		  sort_big.c \
		  sort_big_moves.c \
		  setting_nodes_utils.c \
		  post_sort.c \
		  pre_sort.c
OBJS	= ${SRCS:.c=.o}
INCS	= -IINCS
CC		= gcc -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
