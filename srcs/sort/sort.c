/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 16:17:56 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->stack[2] > a->stack[1]
		&& a->stack[1] < a->stack[0] && a->stack[2] > a->stack[0])
		rotate(a, 1, 'a');
	if (a->stack[2] > a->stack[1] && a->stack[1] > a->stack[0])
		rotate(a, 1, 'a');
	if (a->stack[1] > a->stack[0])
		rev_rotate(a, 1, 'a');
	if (a->stack[2] > a->stack[1])
		swap(a, 1, 'a');
}

void	sort_back_to_a(t_stack *a, t_stack *b)
{
	int	best_insert;
	int	insert_pos;

	while (b->len)
	{
		best_insert = get_best_insert(*a, *b);
		insert_pos = get_insert_pos(*a, best_insert);
		rotate_both(a, insert_pos, b, get_pos(*b, best_insert) + 1);
		push(a, b, 1, 'a');
	}
	min_top(a, 'a');
}

void	sort_more_v1(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		push(b, a, 1, 'b');
	sort_3(a);
	sort_back_to_a(a, b);
}

void	sort_more_v2(t_stack *a, t_stack *b)
{
	int	median;
	int	last_kept;

	median = a->first;
	last_kept = median;
	rotate(a, 1, 'a');
	while (a->first != median)
	{
		if (a->first > last_kept)
		{
			last_kept = a->first;
			rotate(a, 1, 'a');
		}
		else
			push(b, a, 1, 'b');
	}
	sort_back_to_a(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(*a))
		return ;
	if (a->len == 2)
	{
		if (a->first > a->stack[0])
			rotate(a, 1, 'a');
	}
	else if (a->len <= 3)
		sort_3(a);
	else if (a->len <= 5)
		sort_more_v1(a, b);
	else
	{
		if (count_kept_in_a(*a, a->first > 3))
			sort_more_v2(a, b);
		else
			sort_more_v1(a, b);
	}
}
