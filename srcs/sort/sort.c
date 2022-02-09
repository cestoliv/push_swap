/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:55 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/09 09:00:27 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sort_3(t_stack *a, int verbose)
{
	int	inst_num;

	inst_num = 0;
	if (a->stack[2] > a->stack[1])
	{
		swap(a);
		if (verbose)
			ft_printf("sa\n");
		inst_num++;
	}
	if (a->stack[1] > a->stack[0])
	{
		rev_rotate(a);
		if (verbose)
			ft_printf("rra\n");
		inst_num++;
		inst_num += sort_3(a, verbose);
	}
	return (inst_num);
}

/*
	int	median;
	int	last_kept;

	median = get_median(*a);
	//median = a->first;
	//ft_printf("med : %d\nnext_min : %d\n", median, get_min_after(*a, 5));

	rotate_to(a, get_pos(*a, median), 'a'); // median to top
	last_kept = median;
	rotate(a);
	ft_printf("ra\n");
	while (a->first != median)
	{
		if (a->first > last_kept)
		{
			last_kept = a->first;
			rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			push(b, a);
			ft_printf("pb\n");
		}
	}
*/

void	stack_dup(t_stack st, t_stack *dup)
{
	int		cur;

	dup->len = st.len;
	dup->first = st.first;
	dup->stack = malloc(sizeof(int) * dup->len);
	if (!dup->stack)
		exit(EXIT_FAILURE);
	cur = 0;
	while (cur < dup->len)
	{
		dup->stack[cur] = st.stack[cur];
		cur++;
	}
}

int	dry_push_b(t_stack a, t_stack b)
{
	t_stack	tmp_a;
	t_stack	tmp_b;
	int		first;
	int		last_kept;

	stack_dup(a, &tmp_a);
	stack_dup(b, &tmp_b);

	first = tmp_a.first;
	last_kept = first;
	rotate(&tmp_a);
	while (tmp_a.first != first && tmp_a.len)
	{
		if (tmp_a.first > last_kept)
		{
			last_kept = tmp_a.first;
			rotate(&tmp_a);
		}
		else
		{
			push(&tmp_b, &tmp_a);
		}
	}


	//free(tmp_a.stack);
	//free(tmp_b.stack);
	return (tmp_a.len);
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

int	dry_sort_one(t_stack a, t_stack b)
{
	//int		best_insert;
	//int		insert_pos;
	int		inst_num;

	inst_num = 0;
	while (a.len > 3)
	{
		push(&b, &a);
		inst_num++;
	}
	//ft_printf("find duplicates : %d\n", find_duplicates(a));
	inst_num += sort_3(&a, 0);
	/*
	while (b.len)
	{
		best_insert = get_best_insert(a, b);
		insert_pos = get_insert_pos(a, best_insert);
		inst_num += rotate_both_to(&a, insert_pos, &b, get_pos(b, best_insert) + 1, 0);
		push(&a, &b);
		inst_num++;
	}
	inst_num += min_top(&a, 'a', 0);
	*/
	return (inst_num);
}

int	dry_sort_two(t_stack a, t_stack b)
{
	//int		best_insert;
	//int		insert_pos;
	int		inst_num;

	int	median;
	int	last_kept;

	median = a.first;
	inst_num = 0;
	last_kept = median;
	rotate(&a);
	inst_num++;
	while (a.first != median)
	{
		if (a.first > last_kept)
		{
			last_kept = a.first;
			rotate(&a);
			inst_num++;
		}
		else
		{
			push(&b, &a);
			inst_num++;
		}
		if (find_duplicates(b))
		{
			ft_printf("dup\n");
			exit(EXIT_FAILURE);
		}
	}
	/*
	while (b.len)
	{
		best_insert = get_best_insert(a, b);
		insert_pos = get_insert_pos(a, best_insert);
		inst_num += rotate_both_to(&a, insert_pos, &b, get_pos(b, best_insert) + 1, 0);
		push(&a, &b);
		inst_num++;
	}
	inst_num += min_top(&a, 'a', 0);
	*/
	return (inst_num);
}

int	compare_sort(t_stack a, t_stack b)
{
	t_stack	t_a;
	t_stack	t_b;
	int		sort_one;
	int		sort_two;

	stack_dup(a, &t_a);
	stack_dup(b, &t_b);
	sort_one = dry_sort_one(t_a, t_b);
	free(t_a.stack);
	free(t_b.stack);
	stack_dup(a, &t_a);
	stack_dup(b, &t_b);
	sort_two = dry_sort_two(t_a, t_b);
	if (sort_two < sort_one && sort_two > 0)
		return (1);
	return (0);
}

void	sort_more(t_stack *a, t_stack *b)
{
	int	best_insert;
	int	insert_pos;
	int	median;
	int	last_kept;

	if (compare_sort(*a, *b))
	{
		median = a->first;
		last_kept = median;
		rotate(a);
		ft_printf("ra\n");
		while (a->first != median)
		{
			if (a->first > last_kept)
			{
				last_kept = a->first;
				rotate(a);
				ft_printf("ra\n");
			}
			else
			{
				push(b, a);
				ft_printf("pb\n");
			}
		}
	}
	else
	{
		while (a->len > 3)
		{
			push(b, a);
			ft_printf("pb\n");
		}
		sort_3(a, 1);
	}
	while (b->len)
	{
		best_insert = get_best_insert(*a, *b);
		insert_pos = get_insert_pos(*a, best_insert);
		rotate_both_to(a, insert_pos, b, get_pos(*b, best_insert) + 1, 1);
		push(a, b);
		ft_printf("pa\n");
	}
	min_top(a, 'a', 1);
}

void	sort(t_stack *a, t_stack *b)
{
	if (!is_sorted(*a))
	{
		if (a->len <= 3)
			sort_3(a, 1);
		else if (a->len > 3)
			sort_more(a, b);
	}
}
