/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:46:48 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/03 12:22:57 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#ifndef CHECK_VERBOSE
# define CHECK_VERBOSE 0
#endif

int	apply_stack_rot(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		rotate(a);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rotate(b);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rev_rotate(a);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rev_rotate(b);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	apply_stack_op(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		swap(a);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		swap(b);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		push(a, b);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		push(b, a);
	else if (!apply_stack_rot(a, b, line))
		return (0);
	return (1);
}

void	print_stacks(t_stack a, t_stack b, char *line)
{
	int	len;
	int	cur;

	len = a.len;
	if (b.len > len)
		len = b.len;
	cur = 0;
	ft_printf(" > %s", line);
	ft_printf("+------A-------+------B------+\n");
	while (cur < len)
	{
		if (a.len > cur && b.len > cur)
			ft_printf("| % 11d | %-11d |\n",
				a.stack[a.len - 1 - cur], b.stack[b.len - 1 - cur]);
		else if (a.len > cur)
			ft_printf("| % 11d | %11c |\n", a.stack[a.len - 1 - cur], ' ');
		else if (b.len > cur)
			ft_printf("| %12c | %-11d |\n", ' ', b.stack[b.len - 1 - cur]);
		cur++;
	}
	ft_printf("+--------------+-------------+\n");
}

int	check(t_stack *a, t_stack *b)
{
	char	*line;

	(void)*a;
	(void)*b;
	if (CHECK_VERBOSE)
		print_stacks(*a, *b, "start\n");
	line = get_next_line(0, GNL_KEEP);
	while (line)
	{
		if (!apply_stack_op(a, b, line))
			return (0);
		if (CHECK_VERBOSE)
			print_stacks(*a, *b, line);
		line = get_next_line(0, GNL_KEEP);
	}
	if (is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (!make_stacks(&a, &b, argc, argv))
		ft_putstr_fd("Error\n", 2);
	else if (find_duplicates(a))
		ft_putstr_fd("Error\n", 2);
	else if (!check(&a, &b))
		ft_putstr_fd("Error\n", 2);
	free(a.stack);
	free(b.stack);
}
