/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-23 12:30:19 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-23 12:30:19 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, 1);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, 1);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		set_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*bigger;

	bigger = find_max(*a);
	if (bigger == *a)
		ra(a, 1);
	else if ((*a)->next == bigger)
		rra(a, 1);
	if ((*a)->data > (*a)->next->data)
		sa(a, 1);
}

void	set_stack_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_cost(a, b);
	set_cheapest(a);
}

void	set_stack_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
