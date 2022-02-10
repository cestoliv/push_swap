/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:44:53 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:44:54 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

int	get_pos(t_stack st, int num)
{
	int	cur;

	cur = 0;
	while (cur < st.len)
	{
		if (st.stack[cur] == num)
			return (cur);
		cur++;
	}
	return (-1);
}

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
