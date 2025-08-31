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

static void	kill_process(t_stack_node **stack, char **argv, int argc)
{
	if (argc == 2)
		free_arr(argv);
	free_stack(stack);
	error_msg("Error\n");
}

static t_stack_node	*create_node(int value)
{
	t_stack_node	*node;

	node = (t_stack_node*) malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->target_node = NULL;
	node->value = value;
	return (node);
}

static t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static int	append_node(t_stack_node **stack, char *nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	int				value;

	value = ft_atoi(nbr);
	node = create_node(value);
	if (!node)
		return (0);
	if (*stack == NULL)
		*stack = node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (1);
}

void	create_stack(t_stack_node **stack, char **argv, int argc)
{
	int	i;
	int	is_successful;

	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	i = 0;
	while (argv[i] != NULL)
	{
		is_successful = append_node(stack, argv[i]);
		if (!is_successful)
			kill_process(stack, argv, argc);
		i++;
	}
	if (argc == 2)
		free_arr(argv);
}
