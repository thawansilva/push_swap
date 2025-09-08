/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:55:34 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/07 12:55:34 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack_node	*get_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;
	int				smallest_value;

	if (!stack)
		return (NULL);
	smallest_value = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest = stack;
			smallest_value = stack->value;
		}
		stack = stack->next;
	}
	return (smallest);
}

int	get_stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_node	*get_highest(t_stack_node *head)
{
	t_stack_node	*highest;
	int				highest_value;

	if (head == NULL)
		return (NULL);
	highest = NULL;
	highest_value = INT_MIN;
	while (head)
	{
		if (head->value > highest_value)
		{
			highest_value = head->value;
			highest = head;
		}
		head = head->next;
	}
	return (highest);
}

int	is_stack_sorted(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (stack == NULL)
		return (TRUE);
	current = stack;
	while (current->next)
	{
		next = current->next;
		if (current->value > next->value)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
