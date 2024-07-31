/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 21:28:25 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-04 21:28:25 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	b = NULL;
	a = NULL;
	if (ac < 2 || !av[1] || !*av[1])
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac);
	if (check_if_dup(a))
		ft_error_dup(&a, av, ac);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else
			sort_stack(&a, &b);
	}
	if (ac == 2)
		ft_free_av(av);
	free_stack(&a);
	return (0);
}
