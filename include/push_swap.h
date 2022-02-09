/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:07:25 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/08 16:54:40 by ocartier         ###   ########.fr       */
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
void	swap(t_stack *st);
void	sswap(t_stack *s1, t_stack *s2);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *st);
void	rrotate(t_stack *s1, t_stack *s2);
void	rev_rotate(t_stack *st);
void	rrev_rotate(t_stack *s1, t_stack *s2);
// min_max.c
int		get_max(t_stack st);
int		get_min(t_stack st);
int		get_min_pos(t_stack st);
int		get_pos(t_stack st, int num);
// sort_utils.c
int		is_sorted(t_stack st);
int		get_insert_pos(t_stack st, int num);
int		min_top(t_stack *st, char st_name, int verbose);
void	min_top_both(t_stack *a, t_stack *b);
int		get_best_insert(t_stack a, t_stack b);
void	rotate_to(t_stack *st, int st_top, char st_name);
int		rotate_both_to(t_stack *a, int a_top, t_stack *b, int b_top, int verbose);
// sort.c
void	sort(t_stack *a, t_stack *b);
// median.c
int		get_median(t_stack a);
int		get_min_after(t_stack st, int stop);
// parse.c
int		number_of_digits(int argc, char **argv);
int		fill_stack(t_stack *a, int num_digit, char **argv);
// utils.c
int		find_duplicates(t_stack st);
int		make_stacks(t_stack *a, t_stack *b, int argc, char **argv);
#endif
