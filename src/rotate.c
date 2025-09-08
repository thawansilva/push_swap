/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:32:57 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/01 16:32:57 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate_move(t_stack_node **head)
{
	int				len;
	t_stack_node	*last_node;

	len = get_stack_size(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	last_node = get_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate(t_stack_node **stack, char type)
{
	rotate_move(stack);
	ft_printf("r%c\n", type);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_move(stack_a);
	rotate_move(stack_b);
	ft_printf("rr\n");
}
