/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:42:00 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 11:29:32 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*dup_array(int *array, int size)
{
	int	*dup;

	dup = malloc(sizeof(int) * size);
	if (!dup)
		exit(EXIT_FAILURE);
	while (size--)
		dup[size] = array[size];
	return (dup);
}

void	bubble_sort(int *array, int size)
{
	int	cur1;
	int	cur2;
	int	temp;

	cur1 = 0;
	while (cur1 < size - 1)
	{
		cur2 = 0;
		while (cur2 < size - 1 - cur1)
		{
			if (array[cur2] > array[cur2 + 1])
			{
				temp = array[cur2];
				array[cur2] = array[cur2 + 1];
				array[cur2 + 1] = temp;
			}
			cur2++;
		}
		cur1++;
	}
}

int	get_median(t_stack a)
{
	int	*sorted_stack;

	sorted_stack = dup_array(a.stack, a.len);
	bubble_sort(sorted_stack, a.len);

	return sorted_stack[a.len / 2];
}

int	get_min_after(t_stack st, int stop)
{
	int	*sorted_stack;
	int	cur;

	sorted_stack = dup_array(st.stack, st.len);
	bubble_sort(sorted_stack, st.len);
	cur = 0;
	while (cur < st.len - 1)
	{
		if (sorted_stack[cur + 1] > stop)
			break ;
		cur++;
	}
	return (sorted_stack[cur - 1]);
}

int	count_kept_in_a(t_stack a, int num)
{
	int	pivot_pos;
	int	total;
	int	cur;

	total = 0;
	pivot_pos = get_pos(a, num);
	cur = pivot_pos;
	while (cur >= 0)
	{
		if (a.stack[cur] > num)
		{
			num = a.stack[cur];
			total++;
		}
		cur--;
	}
	cur = a.len - 1;
	while (cur > pivot_pos)
	{
		if (a.stack[cur] > num)
		{
			num = a.stack[cur];
			total++;
		}
		cur--;
	}
	return (total);
}

int	get_best_median(t_stack a)
{
	int	cur;
	int	best_median;
	int	best_kept;

	best_kept = count_kept_in_a(a, a.first);
	cur = 0;
	while (cur < a.len - 1)
	{
		int kept = count_kept_in_a(a, a.stack[cur]);

		int op = cur;
		if (op / (double)a.len >= 0.5)
			op = a.len - cur;
		if (kept > best_kept && op < a.len / 5)
		{
			best_kept = kept;
			best_median = a.stack[cur];
		}
		cur++;
	}
	return (best_median);
}
