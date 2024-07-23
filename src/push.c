/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 21:28:37 by jesopan-          #+#    #+#             */
/*   Updated: 2024-06-04 21:28:37 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_node(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_be_push;

	if (!src || !*src)
		return ;
	node_to_be_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_be_push->prev = NULL;
	if (!*dst)
	{
		*dst = node_to_be_push;
		node_to_be_push->next = NULL;
	}
	else
	{
		node_to_be_push->next = *dst;
		node_to_be_push->next->prev = node_to_be_push;
		*dst = node_to_be_push;
	}
}

void	pb(t_stack_node **b, t_stack_node **a, int print)
{
	push_node(b, a);
	if (print == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push_node(a, b);
	if (print == 1)
		write(1, "pa\n", 3);
}
