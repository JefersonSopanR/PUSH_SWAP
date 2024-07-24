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
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1);
	if (check_if_dup(a))
		ft_error(&a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
