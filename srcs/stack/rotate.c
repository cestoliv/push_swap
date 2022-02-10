/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:58:47 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:24:58 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *st, int verbose, char st_name)
{
	int	first;
	int	cur;

	if (st->len > 1)
	{
		cur = st->len - 1;
		first = st->stack[st->len - 1];
		while (cur > 0)
		{
			st->stack[cur] = st->stack[cur - 1];
			cur--;
		}
		st->stack[0] = first;
	}
	st->first = st->stack[st->len - 1];
	if (verbose)
		ft_printf("r%c\n", st_name);
}

void	rrotate(t_stack *s1, t_stack *s2, int verbose)
{
	rotate(s1, 0, 'a');
	rotate(s2, 0, 'b');
	if (verbose)
		ft_printf("rr\n");
}

void	rev_rotate(t_stack *st, int verbose, char st_name)
{
	int	last;
	int	cur;

	if (st->len > 1)
	{
		cur = 0;
		last = st->stack[0];
		while (cur < st->len - 1)
		{
			st->stack[cur] = st->stack[cur + 1];
			cur++;
		}
		st->stack[st->len - 1] = last;
	}
	st->first = st->stack[st->len - 1];
	if (verbose)
		ft_printf("rr%c\n", st_name);
}

void	rrev_rotate(t_stack *s1, t_stack *s2, int verbose)
{
	rev_rotate(s1, 0, 'a');
	rev_rotate(s2, 0, 'b');
	if (verbose)
		ft_printf("rrr\n");
}
