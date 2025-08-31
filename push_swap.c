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

int main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;// O(1)
	stack_b = NULL;// O(1)
	if (argc == 1)
		error_msg("Insert at least one argument, please\n");
	input_validate(argc, argv); // O(n³)
	create_stack(&stack_a, argv + 1, argc); // O(n²)
	order_stack(stack_a, stack_b);
	free_stack(&stack_a); //O(n)
	free_stack(&stack_b); //O(n)
	return (0);
}
