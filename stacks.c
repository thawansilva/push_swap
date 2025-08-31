/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:19:04 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/21 18:19:04 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

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

void	ordenate_stack(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	size_a;

	size_a = get_stack_size(stack_a);
	if (!stack_a && !stack_b)
		return ;
	if (size_a == 2)
		return (order_two(stack_a, 'a'));
	else if (size_a == 3)
		return (order_three(stack_a, 'a'));
}
