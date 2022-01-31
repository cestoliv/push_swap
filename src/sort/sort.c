/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 11:42:25 by ocartier         ###   ########.fr       */
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

int	get_max(t_stack st)
{
	int	cur;
	int	max;

	cur = 0;
	max = st.stack[cur];
	while (cur < st.len)
	{
		if (st.stack[cur] > max)
			max = st.stack[cur];
		cur++;
	}
	return (max);
}

int	get_min(t_stack st)
{
	int	cur;
	int	min;

	cur = 0;
	min = st.stack[cur];
	while (cur < st.len)
	{
		if (st.stack[cur] < min)
			min = st.stack[cur];
		cur++;
	}
	return (min);
}

int	get_min_pos(t_stack st)
{
	int	cur;
	int	min;

	min = 0;
	cur = st.len;
	while (--cur)
		if (st.stack[cur] < st.stack[min])
			min = cur;
	return (min);
}

int	get_insert_pos(t_stack st, int num)
{
	int	cur;

	cur = 0;
	if (num > get_max(st))
		return (0);
	else if (num < get_min(st))
		return (0);
	while (cur < st.len)
	{
		int before = st.stack[cur];
		int after = st.stack[cur - 1];
		if (cur == 0)
			after = st.stack[st.len - 1];
		if (num > before && num < after)
			return (cur);
		cur++;
	}
	return (-1);
}

void	sort_3(t_stack *a)
{
	if (a->stack[2] > a->stack[1])
	{
		swap(a);
		ft_printf("sa\n");
	}
	if (a->stack[1] > a->stack[0])
	{
		rev_rotate(a);
		ft_printf("rra\n");
		sort_3(a);
	}
}
/*
void	sort_5(t_stack *a, t_stack *b)
{
	int	rotations;

	rotations = 0;
	while (a->len > 3)
	{
		push(b, a);
		ft_printf("pb\n");
	}
	sort_3(a);
	while (b->len)
	{
		while (a->stack[a->len - 1] < b->stack[b->len - 1])
		{
			if (rotations >= a->len)
				break ;
			rotate(a);
			ft_printf("ra\n");
			rotations++;
		}
		push(a, b);
		ft_printf("pa\n");
		while (a->stack[a->len - 1] > b->stack[b->len - 1] && rotations)
		{
			rev_rotate(a);
			ft_printf("rra\n");
			rotations--;
		}
	}
	while (rotations)
	{
		rev_rotate(a);
		ft_printf("rra\n");
		rotations--;
	}
}
*/

#include <stdio.h>
void	rot_min_to_top(t_stack *st)
{
	if ((get_min_pos(*st) + 1) / (double)st->len < 0.5)
	{
		while (!is_sorted(*st))
		{
			rev_rotate(st);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (!is_sorted(*st))
		{
			rotate(st);
			ft_printf("ra\n");
		}
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	rotations;

	rotations = 0;
	while (a->len > 3)
	{
		push(b, a);
		ft_printf("pb\n");
	}
	sort_3(a);
	while (b->len)
	{
		int insert_pos = get_insert_pos(*a, b->stack[b->len - 1]);
		//ft_printf("insert pos : %d\n", insert_pos);
		if ((insert_pos + 1) / (double)a->len < 0.5)
		{
			while (insert_pos)
			{
				rev_rotate(a);
				ft_printf("rra\n");
				insert_pos--;
			}
		}
		else
		{
			insert_pos = a->len - insert_pos;
			while (insert_pos)
			{
				rotate(a);
				ft_printf("ra\n");
				insert_pos--;
			}
		}
		push(a, b);
		ft_printf("pa\n");
	}
	//rot_min_to_top(a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->len == 3)
		sort_3(a);
	else if (a->len > 3)
		sort_5(a, b);
}
