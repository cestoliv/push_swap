/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:07:04 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 11:41:32 by ocartier         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		cur_s;
	int		cur_a;
	t_stack	a;
	t_stack	b;

	a.len = argc - 1;
	a.stack = malloc(sizeof(int) * a.len);
	if (!a.stack)
		exit(EXIT_FAILURE);
	b.len = 0;
	b.stack = malloc(sizeof(int) * a.len);
	if (!b.stack)
		exit(EXIT_FAILURE);

	cur_s = a.len;
	cur_a = 1;
	while (cur_s--)
	{
		a.stack[cur_s] = ft_atoi(argv[cur_a]);
		cur_a++;
	}
	sort(&a, &b);
	print_stack(a);
	ft_printf("   b\n");
	print_stack(b);
}
