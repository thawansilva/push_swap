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

void	ordenate_stack(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
		return (ordenate_two_elem(stack_a));
//	if (size == 3)
//		return ();
	if (!stack_a || !stack_b)
		return ;
}
