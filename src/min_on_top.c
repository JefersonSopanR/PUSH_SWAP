/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 21:38:24 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-04 21:38:24 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	min_on_top(t_stack_node **stack)
{
	while ((*stack)->data != find_min(*stack)->data)
	{
		if (find_min(*stack)->above_medium)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}
