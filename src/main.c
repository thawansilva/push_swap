/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:20:45 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/16 10:20:45 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	input_validate(argc, argv); 
	create_stack(&stack_a, argv + 1, argc); 
	if (!is_stack_sorted(stack_a))
	{
		if (get_stack_size(stack_a) == 2)
			swap(&stack_a, 'a', FALSE);
		else if (get_stack_size(stack_a) == 3)
			order_three(&stack_a);
		else
			order_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a); 
	return (0);
}
