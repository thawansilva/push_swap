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

void	swap(t_stack_node	**head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	int	len;

	len = get_stack_size(*head);
	if (!head || !*head || len == 1)
		return ;

}
