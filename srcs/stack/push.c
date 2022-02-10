/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:42:02 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/09 19:29:49 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	if (b->len)
	{
		a->stack[a->len] = b->stack[b->len - 1];
		a->len++;
		b->len--;
		a->first = a->stack[a->len - 1];
		if (b->len)
			b->first = b->stack[b->len - 1];
		else
			b->first = -1;
	}
}
