/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-24 10:00:04 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-24 10:00:04 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_if_dup(t_stack_node *a)
{
	t_stack_node	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->data == a->data)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*cur_a;

	cur_a = *a;
	while (cur_a)
	{
		tmp = cur_a->next;
		cur_a->data = 0;
		free(cur_a);
		cur_a = tmp;
	}
	*a = NULL;
}

bool	stack_sorted(t_stack_node *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

void	ft_error(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_dup(t_stack_node **a, char **av, int ac)
{
	free_stack(a);
	write(2, "Error\n", 6);
	if (ac == 2)
		ft_free_av(av);
	exit(EXIT_FAILURE);
}

bool	error_check(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
		return (true);
	if ((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1])))
		return (true);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}
