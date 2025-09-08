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

#include "push_swap.h"

void	order_three(t_stack_node **head)
{
	t_stack_node	*highest;

	highest = get_highest(*head);
	if (*head == highest)
		rotate(head, 'a', FALSE);
	else if ((*head)->next == highest)
		reverse_rotate(head, 'a', FALSE);
	if ((*head)->value > (*head)->next->value)
		swap(head, 'a', FALSE);
}
