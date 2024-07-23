/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_nodes_from_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 21:28:13 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-04 21:28:13 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_medium && cheapest_node->target->above_medium)
		d_rot(a, b, cheapest_node);
	else if (!cheapest_node->above_medium
		&& !(cheapest_node->target->above_medium))
		r_d_rot(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target, 'b');
	pb(b, a, 1);
}

void	d_rot(t_stack_node **a, t_stack_node **b, t_stack_node *node)
{
	while (*a != node && *b != node->target)
		rr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

void	r_d_rot(t_stack_node **a, t_stack_node **b, t_stack_node *n)
{
	while (*a != n && *b != n->target)
		rrr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *node, char c)
{
	while (*stack != node)
	{
		if (c == 'a')
		{
			if (node->above_medium)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (c == 'b')
		{
			if (node->above_medium)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, 1);
}
