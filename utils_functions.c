/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:22:45 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/18 19:22:45 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void error_msg(char *str)
{
	ft_putstr_fd(str, STDERR);
	exit(1);
}

void free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_numbers(int *arr)
{
	free(arr);
}

void	free_stack(t_list **stack_a)
{
	t_list	*next_node;

	if (!stack_a || !*stack_a)
		return ;
	while (*stack_a)
	{
		next_node = (*stack_a)->next;
		free(*stack_a);
		*stack_a = next_node;
	}
}
