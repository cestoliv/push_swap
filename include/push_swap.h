/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:07:25 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 16:15:07 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack;
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
// sort_utils.c
int		is_sorted(t_stack st);
int		get_insert_pos(t_stack st, int num);
void	rot_min_to_top(t_stack *st);
// sort.c
void	sort(t_stack *a, t_stack *b);
#endif
