/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:05:22 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/02 10:05:22 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_move(t_stack_node **head)
{
	t_stack_node	*last_node;
	int				len;

	len = get_stack_size(*head);
	if (head == NULL || *head == NULL || len == 1)
		return ;
	last_node = get_last_node(*head);
	last_node->next = *head;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*head = last_node;
	last_node->next->prev = last_node;
}

void	reverse_rotate(t_stack_node **stack, char type, int print)
{
	reverse_rotate_move(stack);
	if (!print)
		ft_printf("rr%c\n", type);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	reverse_rotate_move(stack_a);
	reverse_rotate_move(stack_b);
	if (!print)
		ft_printf("rrr\n");
}
