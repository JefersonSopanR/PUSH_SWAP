/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-23 13:16:02 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-23 13:16:02 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_nodes(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, int print)
{
	rotate_nodes(a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, int print)
{
	rotate_nodes(b);
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, int print)
{
	rotate_nodes(a);
	rotate_nodes(b);
	if (print == 1)
		write(1, "rr\n", 3);
}
