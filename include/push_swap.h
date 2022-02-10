/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:07:25 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:59:52 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack;
	int	first;
	int	len;
}	t_stack;

// stack/*.c
void	swap(t_stack *st, int verbose, char st_name);
void	sswap(t_stack *s1, t_stack *s2, int verbose);
void	push(t_stack *a, t_stack *b, int verbose, char st_name);
void	rotate(t_stack *st, int verbose, char st_name);
void	rrotate(t_stack *s1, t_stack *s2, int verbose);
void	rev_rotate(t_stack *st, int verbose, char st_name);
void	rrev_rotate(t_stack *s1, t_stack *s2, int verbose);
// stack/stack_utils.c
int		get_max(t_stack st);
int		get_min(t_stack st);
int		get_pos(t_stack st, int num);
int		is_sorted(t_stack st);
// sort/rotate_both.c
void	rotate_both(t_stack *a, int a_top, t_stack *b, int b_top);
// sort/sort_utils.c
int		get_insert_pos(t_stack st, int num);
void	min_top(t_stack *st, char st_name);
int		get_best_insert(t_stack a, t_stack b);
int		count_kept_in_a(t_stack a, int num);
// sort/sort.c
void	sort(t_stack *a, t_stack *b);
// parse/parse_utils.c
int		make_stacks(t_stack *a, t_stack *b, int argc, char **argv);
int		fill_stack(t_stack *a, int num_digit, char **argv);
// parse/parse.c
int		number_of_digits(int argc, char **argv);
long	atol(const char *str);
int		find_duplicates(t_stack st);
int		is_digit_str(char *str);
int		is_digit_argv(int argc, char **argv);
#endif
