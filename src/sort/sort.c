/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/27 09:51:06 by ocartier         ###   ########.fr       */
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
	push(b, a);
	ft_printf("pb\n");
	push(b, a);
	ft_printf("pb\n");

	sort_3(a);

	if (b->stack[b->len - 1] < a->stack[a->len - 1])
	{
		push(a, b);
		ft_printf("pa\n");
	}
	else if (b->stack[b->len - 1] < a->stack[a->len - 2])
	{
		push(a, b);
		ft_printf("pa\n");
		swap(a);
		ft_printf("sa\n");
	}
	else if (b->stack[b->len - 1] < a->stack[a->len - 3])
	{
		rev_rotate(a);
		ft_printf("rra\n");
		push(a, b);
		ft_printf("pa\n");
		rotate(a);
		ft_printf("ra\n");
		rotate(a);
		ft_printf("ra\n");
	}
	else
	{
		push(a, b);
		ft_printf("pa\n");
		rotate(a);
		ft_printf("ra\n");
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->len == 3)
		sort_3(a);
	else if (a->len == 5)
		sort_5(a, b);
}
