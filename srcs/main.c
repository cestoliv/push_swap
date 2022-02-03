/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:07:04 by ocartier          #+#    #+#             */
/*   Updated: 2022/02/03 09:32:22 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	else
		sort(&a, &b);
	free(a.stack);
	free(b.stack);
}
