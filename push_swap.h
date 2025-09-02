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
# define FALSE 0
# define TRUE 1

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;	
	int					is_above_mid;	
	int					is_cheapest;	
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Stack functions
void			create_stack(t_stack_node **stack_a, char **argv, int is_split);
int				get_stack_size(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);

// Error
void			error_msg(char *str);
void			kill_process(t_stack_node **stack, char **argv, int argc);

// Free Memory
void			free_arr(char **arr);
void			free_stack(t_stack_node **stack_a);

// Validation
void			input_validate(int argc, char **argv);

// Order functions
void			order_two(t_stack_node *stack, char type);
void			order_three(t_stack_node *stack, char type);
void			order_stack(t_stack_node *stack_a, t_stack_node *stack_b);

// Moves
void			swap(t_stack_node **stack, char type);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			push(t_stack_node **src, t_stack_node **dest, char type_dest);
void			rotate(t_stack_node **stack, char type);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate(t_stack_node **stack, char type);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
#endif
