/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:30:05 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/03 09:32:39 by ocartier         ###   ########.fr       */
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

void	rot_min_to_top(t_stack *st, char st_name)
{
	/*
	if ((get_min_pos(*st) + 1) / (double)st->len < 0.5)
	{
		while (!is_sorted(*st))
		{
			rev_rotate(st);
			ft_printf("rr%c\n", st_name);
		}
	}
	else
	{
		while (!is_sorted(*st))
		{
			rotate(st);
			ft_printf("r%c\n", st_name);
		}
	}
	*/
	int	min_pos = get_min_pos(*st) + 1;
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
