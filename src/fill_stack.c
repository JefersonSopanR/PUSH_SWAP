/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-23 10:19:54 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-23 10:19:54 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	append_node(t_stack_node **a, int n)
{
	t_stack_node	*tail;
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->data = n;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail = find_last(*a);
		tail->next = new_node;
		new_node->prev = tail;
	}
}

void	init_stack(t_stack_node **a, char **av, int ac)
{
	int				i;
	long			num;

	i = 0;
	while (av[i])
	{
		if (error_check(av[i]))
		{
			if (ac == 2)
				ft_free_av(av - 1);
			ft_error(a);
		}
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			if (ac == 2)
				ft_free_av(av - 1);
			ft_error(a);
		}
		append_node(a, (int)num);
		i++;
	}
}

void	ft_error_dup(t_stack_node **a, char **av, int ac)
{
	free_stack(a);
	write(2, "Error\n", 6);
	if (ac == 2)
		ft_free_av(av);
	exit(EXIT_FAILURE);
}

void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
