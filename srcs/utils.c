/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:18:50 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/02 11:37:04 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pos_in_stack(t_stack st, int num)
{
	int	cur;

	cur = 0;
	while (cur < st.len)
	{
		if (st.stack[cur] == num)
			return (cur);
		cur++;
	}
	return (-1);
}

int	find_duplicates(t_stack st)
{
	int	cur;

	cur = 0;
	while (cur < st.len)
	{
		if (pos_in_stack(st, st.stack[cur]) != cur)
			return (1);
		cur++;
	}
	return (0);
}

int	is_digit_str(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		if (!ft_isdigit(str[cur]) && str[cur] != ' ')
		{
			if (str[cur] == '-')
			{
				if (!ft_isdigit(str[cur + 1]))
					return (0);
			}
			else
				return (0);
		}
		cur++;
	}
	return (1);
}

int	is_digit_argv(int argc, char **argv)
{
	int	cur;

	cur = 1;
	while (cur < argc)
	{
		if (!is_digit_str(argv[cur]))
			return (0);
		cur++;
	}
	return (1);
}

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
