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
			ft_error(a, av, ac);
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(a, av, ac);
		append_node(a, (int)num);
		i++;
	}
}
