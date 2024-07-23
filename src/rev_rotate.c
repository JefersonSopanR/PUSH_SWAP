/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-23 13:24:11 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-23 13:24:11 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate_nodes(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, int print)
{
	rev_rotate_nodes(a);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int print)
{
	rev_rotate_nodes(b);
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	rev_rotate_nodes(a);
	rev_rotate_nodes(b);
	if (print == 1)
		write(1, "rrr\n", 4);
}
