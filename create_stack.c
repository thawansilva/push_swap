/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:04:14 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/19 16:04:14 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

void	add_elem_stack(t_list **stack, int *nbr)
{
	t_list	*elem;

	elem = ft_lstnew(nbr);
	ft_lstadd_back(stack, elem);
}

void	create_stack(t_list **stack, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		add_elem_stack(stack, &numbers[i]);
		i++;
	}
}
