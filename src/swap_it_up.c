/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_it_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-25 07:39:47 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-25 07:39:47 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_nodes(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, int print)
{
	swap_nodes(a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, int print)
{
	swap_nodes(b);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	swap_nodes(a);
	swap_nodes(b);
	if (print == 1)
		write(1, "ss\n", 3);
}
