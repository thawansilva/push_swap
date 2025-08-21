/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:20:45 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/16 10:20:45 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	t_list	*stack_a;
//	t_list	stack_b;
	int		*numbers;
	int		size;

	if (argc == 1)
		return (1);
	input_validate(argc, argv);
	numbers = get_numbers(argc, argv, &size);
	stack_a = NULL;
	create_stack(&stack_a, numbers, size);
	free_numbers(numbers);
	free_stack(&stack_a);
	return (0);
}
