/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:42:02 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:20:17 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack *a, t_stack *b, int verbose, char st_name)
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
	if (verbose)
		ft_printf("p%c\n", st_name);
}
