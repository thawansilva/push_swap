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
			rotate(head, stack_name, FALSE);
		else
			reverse_rotate(head, stack_name, FALSE);
	}
}

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b, FALSE);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b, FALSE);
	set_current_position(*a);
	set_current_position(*b);
}
