/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:18:50 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/10 15:47:24 by ocartier         ###   ########.fr       */
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

int	find_duplicates(t_stack st)
{
	int	cur;

	cur = 0;
	while (cur < st.len)
	{
		if (get_pos(st, st.stack[cur]) != cur)
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
