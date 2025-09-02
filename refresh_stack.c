/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:22:34 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/02 14:22:34 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *head)
{
	int	i;
	int	mid_list;

	if (head == NULL)
		return ;
	i = 0;
	mid_position = get_stack_size(head) / 2;
	while (head != NULL)
	{
		head->current_position = i;
		if (i <= mid_list)
			head->is_above_mid = TRUE;
		else
			head->is_above_mid = FALSE;
		head = head->next;
		i++;
	}
}

t_stack_node	*get_smallest_node(t_stack_node *head)
{
	t_stack_node	*smallest;

	if (head == NULL)
		return (NULL);
	smallest = head;
	while (head->next)
	{
		if (smallest->value > head->value)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}

void	set_target_node(t_stack_node *head_a, t_stack_node *head_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	int				best_match_value;

	while (head_b != NULL)
	{
		best_match_value = INT_MAX;
		current_a = head_a;
		while (current_a)
		{
			if (current_a->value > head_b->value && 
					current_a->value < best_match_value)
			{
				head_b->target_node = current_a;
				best_match_value = current_a->value
			}
			current_a = current_a->next;
		}
		if (best_match_value == INT_MAX)
			head_b->target_node = get_smallest_node(head);
		else
			head_b->target_node = target;
		head_b = head_b->next;
	}
}

void	set_push_price(t_stack_node *head_a, t_stack_node *head_b)
{

}
