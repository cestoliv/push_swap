/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/02 12:10:36 by ocartier         ###   ########.fr       */
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

void	sort_5(t_stack *a, t_stack *b)
{
	int	insert_pos;

	while (a->len > 3)
	{
		push(b, a);
		ft_printf("pb\n");
	}
	sort_3(a);
	while (b->len)
	{
		insert_pos = get_insert_pos(*a, b->stack[b->len - 1]);
		if ((insert_pos) / (double)a->len < 0.5)
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
	rot_min_to_top(a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (!is_sorted(*a))
	{
		if (a->len <= 3)
			sort_3(a);
		else if (a->len > 3)
			sort_5(a, b);
	}
}
