/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_small_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:22:00 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/30 13:22:00 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack_node	*find_highest_node(t_stack_node *head)
{
	t_stack_node	*highest;

	if (head == NULL)
		return (NULL);
	highest = head;
	while (head->next != NULL)
	{
		if (highest->value < head->next->value)
			highest = head->next;
		head = head->next;
	}
	return (highest);
}

void	order_three(t_stack_node *stack, char type)
{
	t_stack_node	*highest;

	highest = find_highest_node(stack);
	if (stack == highest)
		rotate(&stack, type);
	else if (stack->next == highest)
		reverse_rotate(&stack, type);
	if (stack->value > stack->next->value)
		swap(&stack, type);
}
