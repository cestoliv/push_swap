/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:51:21 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/07 16:56:03 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	number_of_digits(int argc, char **argv)
{
	int	scur;
	int	ccur;
	int	total;

	scur = 0;
	total = 0;
	while (scur < argc)
	{
		ccur = 0;
		while (argv[scur][ccur])
		{
			if (ft_isdigit(argv[scur][ccur]))
				if (argv[scur][ccur + 1] == ' ' || !argv[scur][ccur + 1])
					total += 1;
			ccur++;
		}
		scur++;
	}
	return (total);
}

long	atol(const char *str)
{
	int		cur;
	long	num;
	int		sign;

	cur = 0;
	num = 0;
	sign = 1;
	while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
		cur++;
	if (str[cur] == '+' || str[cur] == '-')
	{
		if (str[cur] == '-')
			sign = -1;
		cur++;
	}
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
	}
	return (num * sign);
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
