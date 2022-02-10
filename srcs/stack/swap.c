/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:39:08 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:25:03 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack *st, int verbose, char st_name)
{
	int	temp;

	if (st->len > 1)
	{
		temp = st->stack[st->len - 1];
		st->stack[st->len - 1] = st->stack[st->len - 2];
		st->stack[st->len - 2] = temp;
	}
	st->first = st->stack[st->len - 1];
	if (verbose)
		ft_printf("s%c\n", st_name);
}

void	sswap(t_stack *s1, t_stack *s2, int verbose)
{
	swap(s1, 0, 'a');
	swap(s2, 0, 'b');
	if (verbose)
		ft_printf("ss\n");
}
