/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-23 10:14:43 by jesopan-          #+#    #+#             */
/*   Updated: 2024-05-23 10:14:43 by jesopan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_medium;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack_node;

void			init_stack(t_stack_node **a, char **av);
int				check_if_dup(t_stack_node *a);
void			free_stack(t_stack_node **a);
void			exit_error(t_stack_node **a);
bool			error_check(char *str);
void			ft_error(t_stack_node **a);
bool			stack_sorted(t_stack_node *a);
void			append_node(t_stack_node **a, int n);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *a);
int				stack_len(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *a);
void			min_on_top(t_stack_node **stack);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			d_rot(t_stack_node **a, t_stack_node **b, t_stack_node *node);
void			r_d_rot(t_stack_node **a, t_stack_node **b, t_stack_node *node);
void			prep_for_push(t_stack_node **stack, t_stack_node *node, char c);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			push_node(t_stack_node **dst, t_stack_node **src);
void			pb(t_stack_node **b, t_stack_node **a, int print);
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			rev_rotate_nodes(t_stack_node **stack);
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);
void			rotate_nodes(t_stack_node **stack);
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);
void			set_index(t_stack_node *stack);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *a);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			set_stack_a(t_stack_node *a, t_stack_node *b);
void			set_stack_b(t_stack_node *a, t_stack_node *b);
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node **b, int print);

#endif