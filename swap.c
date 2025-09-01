/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:59:00 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/31 12:59:00 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_move(t_stack_node	**head)
{
	int	len;

	len = get_stack_size(*head);
	if (!head || !*head || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	swap(t_stack_node **stack, char type)
{
	swap_move(stack);
	ft_printf("s%c\n", type);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_move(stack_a);
	swap_move(stack_b);
	ft_printf("ss\n");
}
