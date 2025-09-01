/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
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

int	is_stack_sorted(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = stack;
	while (current->next)
	{
		next = current->next;
		if (current->value > next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	order_stack(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	size_a;

	if (!stack_a && !stack_b)
		return ;
	if (is_stack_sorted(stack_a))
		return ;
	size_a = get_stack_size(stack_a);
	if (size_a == 2)
		swap(&stack_a, 'a');
	else if (size_a == 3)
		return (order_three(stack_a, 'a'));
}
