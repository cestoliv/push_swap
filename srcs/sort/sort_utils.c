/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:30:05 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/07 11:00:59 by ocartier         ###   ########.fr       */
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

void	rotate_to(t_stack *st, int st_top, char st_name)
{
	st_top += 1;
	if (st_top / (double)st->len < 0.5)
	{
		while (st_top)
		{
			rev_rotate(st);
			ft_printf("rr%c\n", st_name);
			st_top--;
		}
	}
	else
	{
		st_top = st->len - st_top;
		while (st_top)
		{
			rotate(st);
			ft_printf("r%c\n", st_name);
			st_top--;
		}
	}
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
	int	a_dir;
	int	b_dir;

	a_dir = (get_min_pos(*a) + 1) / (double)a->len < 0.5;
	b_dir = (get_min_pos(*b) + 1) / (double)b->len < 0.5;
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

void	rotate_both_to(t_stack *a, int a_top, t_stack *b, int b_top)
{
	int	a_top_t;
	int	b_top_t;
	int	a_dir;
	int	b_dir;

	a_top_t = a_top + 1;
	b_top_t = b_top + 1;
	a_dir = (a_top + 1) / (double)a->len < 0.5;
	b_dir = (b_top + 1) / (double)b->len < 0.5;
	while (a_top != a->first && b_top != b->first)
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
	if (a_top != a->first)
		rotate_to(a, a_top, 'a');
	if (b_top != b->first)
		rotate_to(b, b_top, 'b');
}

int	get_best_insert(t_stack a, t_stack b)
{
	int	insert_pos;
	int	num_op;
	int	best;
	int	best_op;
	int	cur;

	best = -1;
	best_op = -1;
	cur = 0;
	while (cur < b.len)
	{
		insert_pos = get_insert_pos(a, b.stack[b.len - 1 - cur]);
		if ((insert_pos) / (double)a.len < 0.5)
			num_op = insert_pos;
		else
			num_op = a.len - insert_pos;

		insert_pos = cur;
		if (insert_pos / (double)b.len < 0.5)
			num_op += insert_pos;
		else
			num_op += (b.len - insert_pos);

		//ft_printf("nb op : %d, num : %d\n", num_op, b.stack[b.len - 1 - cur]);

		if (best_op < 0 || num_op < best_op)
		{
			best_op = num_op;
			best = b.stack[b.len - 1 - cur];
		}

		cur++;
	}
	return (best);
}
