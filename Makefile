NAME		:=	push_swap

CC			:=	clang -Wall -Werror -Wextra -g
FLAGS		:=	-Llibft -lft

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	include

P_LST_SRCS	:=	main.c \
				parse.c \
				utils.c \
				stack/swap.c \
				stack/push.c \
				stack/rotate.c \
				sort/min_max.c \
				sort/sort_utils.c \
				sort/sort.c
P_LST_OBJS	:=	$(P_LST_SRCS:.c=.o)
C_LST_SRCS	:=	checker.c \
				parse.c \
				utils.c \
				stack/swap.c \
				stack/push.c \
				stack/rotate.c \
				sort/min_max.c \
				sort/sort_utils.c
C_LST_OBJS	:=	$(C_LST_SRCS:.c=.o)
LST_INCS	:=	push_swap.h

P_SRCS		:=	$(addprefix $(DIR_SRCS)/, $(P_LST_SRCS))
C_SRCS		:=	$(addprefix $(DIR_SRCS)/, $(C_LST_SRCS))
P_OBJS		:=	$(addprefix $(DIR_OBJS)/, $(P_LST_OBJS))
C_OBJS		:=	$(addprefix $(DIR_OBJS)/, $(C_LST_OBJS))
INCS		:=	$(addprefix $(DIR_INCS)/, $(LST_INCS))

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile libft/libft.a
	mkdir -p $(DIR_OBJS)
	mkdir -p $(DIR_OBJS)/stack
	mkdir -p $(DIR_OBJS)/sort
	$(CC) -D CHECK_VERBOSE=1 -I $(DIR_INCS) -c $< -o $@
	printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all:		libft $(NAME) checker

$(NAME):	$(P_OBJS)
	$(CC) $(P_OBJS) $(FLAGS) -o $@
	printf "$(ERASE)$(GREEN)$@ made\n$(END)"

checker:	$(C_OBJS)
	$(CC) $(C_OBJS) $(FLAGS) -o $@
	printf "$(ERASE)$(GREEN)$@ made\n$(END)"

libft:
	make -C libft

clean:
	printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	rm -rdf $(DIR_OBJS)
	printf "libft : "
	make clean -C libft

fclean:		clean
	printf "$(YELLOW)$(NAME) removed$(END)\n"
	rm -rf $(NAME) checker
	printf "libft : "
	make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
.SILENT:
