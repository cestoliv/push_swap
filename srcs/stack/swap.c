/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:39:08 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/03 11:57:36 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack *st)
{
	int	temp;

	if (st->len > 1)
	{
		temp = st->stack[st->len - 1];
		st->stack[st->len - 1] = st->stack[st->len - 2];
		st->stack[st->len - 2] = temp;
	}
	st->first = st->stack[st->len - 1];
}

void	sswap(t_stack *s1, t_stack *s2)
{
	swap(s1);
	swap(s2);
}
