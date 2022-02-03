/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:30:05 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/03 10:38:01 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack st)
{
	int	cur;

	cur = 0;
	while (cur < st.len - 1)
	{
		if (st.stack[cur] < st.stack[cur + 1])
			return (0);
		cur++;
	}
	return (1);
}

int	get_insert_pos(t_stack st, int num)
{
	int	cur;
	int	before;
	int	after;

	cur = 0;
	while (cur < st.len)
	{
		before = st.stack[cur];
		after = st.stack[cur - 1];
		if (cur == 0)
			after = st.stack[st.len - 1];
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

	min_pos = get_min_pos(*st) + 1;
	if ((min_pos) / (double)st->len < 0.5)
	{
		while (min_pos)
		{
			rev_rotate(st);
			ft_printf("rr%c\n", st_name);
			min_pos--;
		}
	}
	else
	{
		min_pos = st->len - min_pos;
		while (min_pos)
		{
			rotate(st);
			ft_printf("r%c\n", st_name);
			min_pos--;
		}
	}
}

void	min_top_both(t_stack *a, t_stack *b)
{
	int	min_pos_a;
	int	min_pos_b;
	int	a_dir;
	int	b_dir;

	min_pos_a = get_min_pos(*a) + 1;
	min_pos_b = get_min_pos(*b) + 1;
	a_dir = (min_pos_a) / (double)a->len < 0.5;
	b_dir = (min_pos_b) / (double)b->len < 0.5;
	while (get_min(*a) != a->first && get_min(*b) != b->first)
	{
		if (a_dir && b_dir)
		{
			rrev_rotate(a, b);
			ft_printf("rrr\n");
		}
		else if (!a_dir && !b_dir)
		{
			rrotate(a, b);
			ft_printf("rr\n");
		}
		else if (a_dir && !b_dir)
		{
			rev_rotate(a);
			ft_printf("rra\n");
			rotate(b);
			ft_printf("rb\n");
		}
		else if (!a_dir && b_dir)
		{
			rotate(a);
			ft_printf("ra\n");
			rev_rotate(b);
			ft_printf("rrb\n");
		}
	}
	if (get_min(*a) != a->first)
		min_top(a, 'a');
	if (get_min(*b) != b->first)
		min_top(b, 'b');
}
