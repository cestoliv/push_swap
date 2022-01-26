/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:07:04 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/26 11:15:07 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack st)
{
	int	cur;

	cur = st.len;
	while (cur--)
		ft_printf("%d\n", st.stack[cur]);
}

int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.len = 5;
	a.stack = malloc(sizeof(int) * a.len);
	if (!a.stack)
		exit(EXIT_FAILURE);
	b.len = 0;
	b.stack = malloc(sizeof(int) * a.len);
	if (!b.stack)
		exit(EXIT_FAILURE);

	a.stack[0] = 5; a.stack[1] = 6; a.stack[2] = 1; a.stack[3] = 9; a.stack[4] = -1;
	swap(&a);
	push(&b, &a);
	rotate(&a);
	rev_rotate(&a);
	ft_printf("   a\n");
	print_stack(a);
	ft_printf("   b\n");
	print_stack(b);
}
