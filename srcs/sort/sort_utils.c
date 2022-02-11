/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:30:05 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/11 07:59:58 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_insert_pos(t_stack st, int num)
{
	int	cur;
	int	before;
	int	after;

	cur = 0;
	while (cur < st.len)
	{
		before = st.stack[cur];
		if (cur == 0)
			after = st.stack[st.len - 1];
		else
			after = st.stack[cur - 1];
		if (num > get_max(st) && before == get_max(st))
			return (cur);
		else if (num < get_min(st) && after == get_min(st))
			return (cur);
		else if (num > before && num < after)
			return (cur);
		cur++;
	}
	return (-1);
}

void	min_top(t_stack *st, char st_name)
{
	int	min_pos;

	min_pos = get_pos(*st, get_min(*st)) + 1;
	if ((min_pos) / (double)st->len < 0.5)
	{
		while (min_pos)
		{
			rev_rotate(st, 1, st_name);
			min_pos--;
		}
	}
	else
	{
		min_pos = st->len - min_pos;
		while (min_pos)
		{
			rotate(st, 1, st_name);
			min_pos--;
		}
	}
}

int	get_best_insert(t_stack a, t_stack b)
{
	int	num_op;
	int	best;
	int	best_op;
	int	cur;

	best = -1;
	best_op = -1;
	cur = 0;
	while (cur < b.len)
	{
		num_op = get_insert_pos(a, b.stack[b.len - 1 - cur]);
		if ((num_op) / (double)a.len >= 0.5)
			num_op = a.len - num_op;
		if (cur / (double)b.len < 0.5)
			num_op += cur;
		else
			num_op += (b.len - cur);
		if (best_op < 0 || num_op < best_op)
		{
			best_op = num_op;
			best = b.stack[b.len - 1 - cur];
		}
		cur++;
	}
	return (best);
}

int	count_kept_in_a(t_stack a, int num)
{
	int	pivot_pos;
	int	total;
	int	cur;

	total = 0;
	pivot_pos = get_pos(a, num);
	cur = pivot_pos;
	while (cur-- > 0)
	{
		if (a.stack[cur] > num)
		{
			num = a.stack[cur];
			total++;
		}
	}
	cur = a.len - 1;
	while (cur-- > pivot_pos)
	{
		if (a.stack[cur] > num)
		{
			num = a.stack[cur];
			total++;
		}
	}
	return (total);
}
