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

void	ordenate_two_elem(t_list *stack)
{
	int	first;
	int	second;

	first = *(int *)stack->content;
	second = *(int *)stack->next->content;
	if (first > second)
		ft_putstr_fd("sa", STDOUT);
}

void	ordenate_three_elem(t_list *stack)
{
	int	*first;
	int	*second;
	int	*third;

	first = stack->content;
	second = stack->next->content;
	third = stack->next->next->content;
	if (*first > *second)
	{
		if (*first > *third && *second > *third)
			return (ft_putstr_fd("ra\nsa\n", STDOUT));
		else if (*first > *third && *second < *third)
			return (ft_putstr_fd("ra\n", STDOUT));
		else
			return (ft_putstr_fd("sa\n", STDOUT));
	}
	else
	{
		if (*second > *third && *first < *third)
			return (ft_putstr_fd("rra\nsa\n", STDOUT));
		else if (*second > *third && *first > *third)
			return (ft_putstr_fd("rra\n", STDOUT));
	}
}

void	ordenate_stack(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		return (ordenate_two_elem(stack_a));
	if (size == 3)
		return (ordenate_three_elem(stack_a));
	if (!stack_a || !stack_b)
		return ;
}
