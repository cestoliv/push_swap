/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:58:47 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/26 11:14:43 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *st)
{
	int	first;
	int	cur;

	if (st->len > 1)
	{
		cur = st->len;
		first = st->stack[st->len - 1];
		while (cur--)
		{
			st->stack[cur] = st->stack[cur - 1];
		}
		st->stack[0] = first;
	}
}

void	rrotate(t_stack *s1, t_stack *s2)
{
	rotate(s1);
	rotate(s2);
}

void	rev_rotate(t_stack *st)
{
	int	last;
	int	cur;

	if (st->len > 1)
	{
		cur = 0;
		last = st->stack[0];
		while (cur < st->len)
		{
			st->stack[cur] = st->stack[cur + 1];
			cur++;
		}
		st->stack[st->len - 1] = last;
	}
}

void	rrev_rotate(t_stack *s1, t_stack *s2)
{
	rev_rotate(s1);
	rev_rotate(s2);
}
