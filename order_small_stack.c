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

void	order_two(t_stack_node *stack, char type)
{
	int	first;
	int	second;

	first = stack->value;
	second = stack->next->value;
	if (first > second)
		ft_printf("s%c\n", type);
}

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
			ft_printf("r%c\ns%c\n", type, type);
		else if (first > third && second < third)
			ft_printf("r%c\n", type);
		else
			ft_printf("s%c\n", type);
	}
	else
	{
		if (second > third && first < third)
			ft_printf("rr%c\ns%c\n", type, type);
		else if (second > third && first > third)
			ft_printf("rr%c\n", type);
	}
}

