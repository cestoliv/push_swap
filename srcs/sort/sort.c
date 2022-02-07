/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/07 11:15:01 by ocartier         ###   ########.fr       */
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
		insert_pos = get_insert_pos(*a, b->first);
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
	min_top(a, 'a');
}

void	sort_new(t_stack *a, t_stack *b)
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
		rotate_to(a, insert_pos - 1, 'a');
		rotate_to(b, get_pos(*b, best_insert), 'b');
		//rotate_both_to(a, insert_pos - 1, b, get_pos(*b, best_insert));
		push(a, b);
		ft_printf("pa\n");
	}
	min_top(a, 'a');
}

void	print_stack(t_stack st)
{
	while (st.len--)
		ft_printf(" %d\n", st.stack[st.len]);
}

void	sort(t_stack *a, t_stack *b)
{
	if (!is_sorted(*a))
	{
		if (a->len <= 3)
			sort_3(a);
		else if (a->len > 3)
			sort_new(a, b);
	}
	/*
	if (is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	print_stack(*a);
	ft_printf("   b");
	print_stack(*b);
	*/
}
