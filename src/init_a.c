/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:40:20 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/07 13:40:20 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target;
	int				best_match_index;

	while (a != NULL)
	{
		best_match_index = INT_MIN;
		current_b = b;
		while (current_b != NULL)
		{
			if (current_b->value < a->value && 
					current_b->value > best_match_index)
			{
				target = current_b;
				best_match_index = current_b->value;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a->target_node = get_highest(b);
		else
			a->target_node = target;
		a = a->next;
	}
}
void	set_price_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(a);
	len_b = get_stack_size(b);
	while (a != NULL)
	{
		a->push_price = a->current_position;
		if (!(a->is_above_mid))
			a->push_price = len_a - (a->current_position);
		if (a->target_node->is_above_mid)
			a->push_price += a->target_node->current_position;
		else
			a->push_price += len_b - (a->target_node->current_position);
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *head_a, t_stack_node *head_b)
{
	set_current_position(head_a);
	set_current_position(head_b);
	set_target_a(head_a, head_b);
	set_price_a(head_a, head_b);
	set_cheapest(head_a);
}

void	move_nodes_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->is_above_mid && cheapest->target_node->is_above_mid)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!cheapest->is_above_mid && !cheapest->target_node->is_above_mid)
		reverse_rotate_both(stack_a, stack_b, cheapest);
	finish_rotation(stack_a, cheapest, 'a');
	finish_rotation(stack_b, cheapest->target_node, 'b');
	push(stack_a, stack_b, 'b', FALSE);
}
