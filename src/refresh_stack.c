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
	int	mid_position;

	if (head == NULL)
		return ;
	i = 0;
	mid_position = get_stack_size(head) / 2;
	while (head != NULL)
	{
		head->current_position = i;
		if (i <= mid_position)
			head->is_above_mid = TRUE;
		else
			head->is_above_mid = FALSE;
		head = head->next;
		i++;
	}
}

void	set_cheapest(t_stack_node *head)
{
	t_stack_node	*cheapest;
	int				best_match_value;

	if (head == NULL)
		return ;
	best_match_value = INT_MAX;
	while (head)
	{
		if (head->push_price < best_match_value)
		{
			best_match_value = head->push_price;
			cheapest = head;
		}
		head = head->next;
	}
	cheapest->is_cheapest = TRUE;
}
