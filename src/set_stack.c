/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-23 11:23:46 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-23 11:23:46 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_stack_node *stack)
{
	int		i;
	int		medium;

	i = 0;
	medium = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= medium)
			stack->above_medium = true;
		else
			stack->above_medium = false;
		i++;
		stack = stack->next;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*cur_b;
	long			target;

	while (a)
	{
		cur_b = b;
		target = LONG_MIN;
		while (cur_b)
		{
			if (cur_b->data < a->data && cur_b->data > target)
			{
				target = cur_b->data;
				target_node = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (target == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*cur_a;
	long			target;

	while (b)
	{
		cur_a = a;
		target = LONG_MAX;
		while (cur_a)
		{
			if (cur_a->data > b->data && cur_a->data < target)
			{
				target = cur_a->data;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (target == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	{
		while (a)
		{
			a->push_cost = a->index;
			if (!(a->above_medium))
				a->push_cost = len_a - (a->index);
			if (a->target->above_medium)
				a->push_cost += a->target->index;
			else
				a->push_cost += len_b - (a->target->index);
			a = a->next;
		}
	}
}

void	set_cheapest(t_stack_node *a)
{
	t_stack_node	*cheapest_node;
	long			cheap;

	cheap = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheap)
		{
			cheap = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}
