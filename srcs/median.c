/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:42:00 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/07 16:22:41 by ocartier         ###   ########.fr       */
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
