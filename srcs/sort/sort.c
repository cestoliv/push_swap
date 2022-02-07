/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/07 23:24:44 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	int	median;
	int	last_kept;

	median = get_median(*a);
	//median = a->first;
	//ft_printf("med : %d\nnext_min : %d\n", median, get_min_after(*a, 5));

	rotate_to(a, get_pos(*a, median), 'a'); // median to top
	last_kept = median;
	rotate(a);
	ft_printf("ra\n");
	while (a->first != median)
	{
		if (a->first > last_kept)
		{
			last_kept = a->first;
			rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			push(b, a);
			ft_printf("pb\n");
		}
	}
*/

void	sort_more(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		push(b, a);
		ft_printf("pb\n");
	}
	sort_3(a);
	while (b->len)
	{
		int best_insert = get_best_insert(*a, *b);
		int insert_pos = get_insert_pos(*a, best_insert);
		rotate_both_to(a, insert_pos, b, get_pos(*b, best_insert) + 1);
		push(a, b);
		ft_printf("pa\n");
	}
	min_top(a, 'a');
}

void	sort(t_stack *a, t_stack *b)
{
	if (!is_sorted(*a))
	{
		if (a->len <= 3)
			sort_3(a);
		else if (a->len > 3)
			sort_more(a, b);
	}
}
