NAME		:=	push_swap

CC			:=	clang -Wall -Werror -Wextra
FLAGS		:=	-Llibft -lft

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	include

LST_SRCS	:=	main.c \
				stack/swap.c \
				stack/push.c \
				stack/rotate.c \
				sort/min_max.c \
				sort/sort_utils.c \
				sort/sort.c
LST_OBJS	:=	$(LST_SRCS:.c=.o)
LST_INCS	:=	push_swap.h

SRCS		:=	$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS		:=	$(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS		:=	$(addprefix $(DIR_INCS)/, $(LST_INCS))

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile libft/libft.a
	@mkdir -p $(DIR_OBJS)
	@mkdir -p $(DIR_OBJS)/stack
	@mkdir -p $(DIR_OBJS)/sort
	@$(CC) -I $(DIR_INCS) -c $< -o $@
	@printf "$(ERASE)$(BLUE) > Compilation :$(END) $<"

all:		libft $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $^ $(FLAGS) -o $@
	@printf "$(ERASE)$(GREEN)$@ made\n$(END)"

libft:
	@make -C libft

clean:
	@printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	@rm -rdf $(DIR_OBJS)
	@printf "libft : "
	@make clean -C libft

fclean:		clean
	@printf "$(YELLOW)$(NAME) removed$(END)\n"
	@rm -rf $(NAME)
	@printf "libft : "
	@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
