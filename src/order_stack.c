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

void	order_three(t_stack_node **head)
{
	t_stack_node	*highest;

	highest = get_highest(*head);
	if (*head == highest)
		rotate(head, 'a');
	else if ((*head)->next == highest)
		reverse_rotate(head, 'a');
	if ((*head)->value > (*head)->next->value)
		swap(head, 'a');
}

void	order_stack(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*smallest;
	int				size_a;

	size_a = get_stack_size(*head_a);
	if ((*head_a)->value > (*head_a)->next->value)
		swap(head_a, 'a');
	if (size_a-- > 3 && !is_stack_sorted(*head_a))
		push(head_a, head_b, 'b');
	if (size_a-- > 3 && !is_stack_sorted(*head_a))
		push(head_a, head_b, 'b');
	while (size_a-- > 3 && !is_stack_sorted(*head_a))
	{
		init_nodes_a(*head_a, *head_b);
		move_nodes_a(head_a, head_b);
	}
	order_three(head_a);
	while (*head_b)
	{
		init_nodes_b(*head_a, *head_b);
		move_nodes_b(head_a, head_b);
	}
	set_current_position(*head_a);
	smallest = get_smallest(*head_a);
	finish_rotation(head_a, smallest, 'a');
}
