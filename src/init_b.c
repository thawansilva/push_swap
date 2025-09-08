/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:00:12 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/03 17:00:12 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	int				best_match_index;

	while (b != NULL)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && 
					current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target_node = get_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *head_a, t_stack_node *head_b)
{
	set_current_position(head_a);
	set_current_position(head_b);
	set_target_b(head_a, head_b);
}

void	move_nodes_b(t_stack_node **a, t_stack_node **b)
{
	finish_rotation(a, (*b)->target_node, 'a');
	push(b, a, 'a', FALSE);
}
