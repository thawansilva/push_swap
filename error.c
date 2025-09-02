/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:38:37 by thaperei          #+#    #+#             */
/*   Updated: 2025/09/02 10:38:37 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char *str)
{
	ft_putstr_fd(str, STDERR);
	exit(1);
}

void	kill_process(t_stack_node **stack, char **argv, int argc)
{
	if (argc == 2)
		free_arr(argv);
	if (stack != NULL)
		free_stack(stack);
	error_msg("Error\n");
}
