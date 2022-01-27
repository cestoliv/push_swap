NAME	=	push_swap
SRCS	=	src/main.c \
			src/stack/swap.c \
			src/stack/push.c \
			src/stack/rotate.c \
			src/sort/sort.c
OBJS	=	${SRCS:.c=.o}
HEADERS	=	include/push_swap.h
CC		=	clang -Wall -Werror -Wextra
CC_F	=	-Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

all:		libft ${NAME}

${NAME}:	${OBJS} ${HEADERS}
			${CC} ${SRCS} ${CC_F} -o ${NAME}

libft:
			@make -C libft

clean:
			rm -rdf ${OBJS}

fclean:		clean
			rm -rdf ${NAME}

.PHONY:		all libft clean fclean
