/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:19:04 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/21 18:19:04 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*smallest;
	int				size_a;

	size_a = get_stack_size(*stack_a);
	if (size_a-- > 3 && !is_stack_sorted(*stack_a))
		push(stack_a, stack_b, 'b', FALSE);
	if (size_a-- > 3 && !is_stack_sorted(*stack_a))
		push(stack_a, stack_b, 'b', FALSE);
	while (size_a-- > 3 && !is_stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_nodes_a(stack_a, stack_b);
	}
	order_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_nodes_b(stack_a, stack_b);
	}
	set_current_position(*stack_a);
	smallest = get_smallest(*stack_a);
	finish_rotation(stack_a, smallest, 'a');
}
