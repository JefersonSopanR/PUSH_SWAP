/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-15 19:44:22 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-15 19:44:22 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	error_operation(char *operation)
{
	write(2, "Error\n", 6);
	free(operation);
	exit(1);
}

static void	apply_operation(char *operation, t_stack_node **a, t_stack_node **b)
{
	if (ft_strncmp(operation, "sa", 2) == 0 && operation[2] == '\n')
		sa(a, 0);
	else if (ft_strncmp(operation, "sb", 2) == 0 && operation[2] == '\n')
		sb(b, 0);
	else if (ft_strncmp(operation, "ss", 2) == 0 && operation[2] == '\n')
		ss(a, b, 0);
	else if (ft_strncmp(operation, "pa", 2) == 0 && operation[2] == '\n')
		pa(a, b, 0);
	else if (ft_strncmp(operation, "pb", 2) == 0 && operation[2] == '\n')
		pb(b, a, 0);
	else if (ft_strncmp(operation, "ra", 2) == 0 && operation[2] == '\n')
		ra(a, 0);
	else if (ft_strncmp(operation, "rb", 2) == 0 && operation[2] == '\n')
		rb(b, 0);
	else if (ft_strncmp(operation, "rr", 2) == 0 && operation[2] == '\n')
		rr(a, b, 0);
	else if (ft_strncmp(operation, "rra", 3) == 0 && operation[3] == '\n')
		rra(a, 0);
	else if (ft_strncmp(operation, "rrb", 3) == 0 && operation[3] == '\n')
		rrb(b, 0);
	else if (ft_strncmp(operation, "rrr", 3) == 0 && operation[3] == '\n')
		rrr(a, b, 0);
	else
		error_operation(operation);
	return ;
}

static void	process_operations(t_stack_node **a, t_stack_node **b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		apply_operation(operation, a, b);
		free(operation);
		operation = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || !av[1] || !*av[1])
	{
		exit(1);
	}
	if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1);
	if (check_if_dup(a))
		ft_error(&a);
	process_operations(&a, &b);
	if (stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
