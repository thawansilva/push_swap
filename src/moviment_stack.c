/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:49:26 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/03 16:49:26 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack_node **head, t_stack_node *cheapest,
		char stack_name)
{
	while (*head != cheapest)
	{
		if ((cheapest)->is_above_mid)
			rotate(head, stack_name);
		else
			reverse_rotate(head, stack_name);
	}
}

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	move_nodes_a(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*head_a);
	if (cheapest->is_above_mid && cheapest->target_node->is_above_mid)
		rotate_both(head_a, head_b, cheapest);
	else if (!cheapest->is_above_mid && !cheapest->target_node->is_above_mid)
		reverse_rotate_both(head_a, head_b, cheapest);
	finish_rotation(head_a, cheapest, 'a');
	finish_rotation(head_b, cheapest->target_node, 'b');
	push(head_a, head_b, 'b');
}

void	move_nodes_b(t_stack_node **a, t_stack_node **b)
{
	finish_rotation(a, (*b)->target_node, 'a');
	push(b, a, 'a');
}
