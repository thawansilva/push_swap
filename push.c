/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:08:45 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/01 12:08:45 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_move(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_pop;

	if (!*src)
		return ;
	node_pop = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_pop->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_pop;
		node_pop->next = NULL;
		return ;
	}
	node_pop->next = *dest;
	node_pop->next->prev = node_pop;
	*dest = node_pop;
}

void	push(t_stack_node **src, t_stack_node **dest, char type_dest)
{
	push_move(src, dest);
	ft_printf("p%c\n", type_dest);
}
