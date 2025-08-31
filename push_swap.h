/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:30:38 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/16 16:30:38 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# define STDERR 2
# define INT_MAX 2147483647 
# define INT_MIN -2147483648

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					final_index;	
	int					push_price;	
	int					is_above_median;	
	int					is_cheapest;	
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Stack functions
void	create_stack(t_stack_node **stack_a, char **argv, int is_split);
void	order_stack(t_stack_node *stack_a, t_stack_node *stack_b);
int		get_stack_size(t_stack_node *stack);

// Utils functions
void	error_msg(char *str);
void	free_arr(char **arr);
void	free_stack(t_stack_node **stack_a);

// Validation
void	input_validate(int argc, char **argv);

// Order functions
void	order_two(t_stack_node *stack, char type);
void	order_three(t_stack_node *stack, char type);
#endif
