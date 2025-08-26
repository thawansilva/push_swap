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
	t_list	*stack_a;
	t_list	*stack_b;
	int		*numbers;
	int		size;

	if (argc == 1)
		return (1);
	input_validate(argc, argv); // O(n³)
	numbers = get_numbers(argc, argv, &size); // O(n²)
	stack_a = NULL;// O(1)
	stack_b = NULL;// O(1)
	create_stack(&stack_a, numbers, size); // O(n²)
	ordenate_stack(stack_a, stack_b, size);
	free_numbers(numbers); // O(1)
	free_stack(&stack_a); //O(n)
	return (0);
}
