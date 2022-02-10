/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:51:21 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:47:20 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	make_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		num_digit;

	num_digit = number_of_digits(argc, argv);
	a->len = num_digit;
	a->stack = malloc(sizeof(int) * num_digit);
	if (!a->stack)
		exit(EXIT_FAILURE);
	b->len = 0;
	b->stack = malloc(sizeof(int) * num_digit);
	if (!b->stack)
		exit(EXIT_FAILURE);
	if (!is_digit_argv(argc, argv))
		return (0);
	return (fill_stack(a, num_digit, argv));
}

int	fill_stack(t_stack *a, int num_digit, char **argv)
{
	int		scur;
	char	**splitted;
	int		pcur;
	long	lnum;

	scur = 1;
	while (num_digit)
	{
		pcur = 0;
		splitted = ft_split(argv[scur++], ' ');
		if (!splitted)
			exit(EXIT_FAILURE);
		while (splitted[pcur])
		{
			lnum = atol(splitted[pcur++]);
			if (lnum > 2147483647 || lnum < -2147483648)
				return (0);
			a->stack[num_digit-- - 1] = (int)lnum;
		}
		while (pcur--)
			free(splitted[pcur]);
		free(splitted);
	}
	a->first = a->stack[a->len - 1];
	return (1);
}
