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
	//t_list	stack_a;
	//t_list	stack_b;
	int		*numbers;

	if (argc == 1)
		return (1);
	input_validate(argc, argv);
	numbers = get_numbers(argc, argv);
	free_numbers(&numbers);
	//create_stack(stack_a, argv);
	return (0);
}
