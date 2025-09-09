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

static void	set_target_a(t_stack_node *a, t_stack_node *b)
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
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
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

static void	set_price_a(t_stack_node *a, t_stack_node *b)
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

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_a(a, b);
	set_price_a(a, b);
	set_cheapest(a);
}
