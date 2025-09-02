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

#include "./push_swap.h"

void	order_three(t_stack_node *stack, char type)
{
	int	first;
	int	second;
	int	third;

	first = stack->value;
	second = stack->next->value;
	third = stack->next->next->value;
	if (first > second)
	{
		if (first > third && second > third)
		{
			rotate(&stack, type);
			swap(&stack, type);
		}
		else if (first > third && second < third)
			rotate(&stack, type);
		else
			swap(&stack, type);
		return ;
	}
	if (second > third && first < third)
	{
		reverse_rotate(&stack, type);
		swap(&stack, type);
	}
	else if (second > third && first > third)
		reverse_rotate(&stack, type);
}
