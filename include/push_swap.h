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
# include "libft.h"
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
void			create_stack(t_stack_node **stack, char **argv, int is_split);
void			finish_rotation(t_stack_node **stack, t_stack_node *cheapest, char stack_name);
t_stack_node	*get_last_node(t_stack_node *stack);

// Utils stack functions
int				is_stack_sorted(t_stack_node *stack);
int				get_stack_size(t_stack_node *stack);
t_stack_node	*get_smallest(t_stack_node *stack);
t_stack_node	*get_highest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

// Refresh Stack
void			set_current_position(t_stack_node *head);
void			set_push_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *head);

// Init calls
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

// Validation
void			input_validate(int argc, char **argv);

// Order functions
void			order_two(t_stack_node *head, char type);
void			order_three(t_stack_node **head);
void			order_stack(t_stack_node **head_a, t_stack_node **head_b);

// Move calls
void			move_nodes_a(t_stack_node **a, t_stack_node **b);
void			move_nodes_b(t_stack_node **b, t_stack_node **a);
void			rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);

// Moves
void			swap(t_stack_node **head, char type);
void			ss(t_stack_node **head_a, t_stack_node **head_b);
void			push(t_stack_node **src, t_stack_node **dest, char type_d);
void			rotate(t_stack_node **head, char type);
void			rr(t_stack_node **head_a, t_stack_node **head_b);
void			reverse_rotate(t_stack_node **head, char type);
void			rrr(t_stack_node **head_a, t_stack_node **head_b);

// Free Memory
void			free_arr(char **arr);
void			free_stack(t_stack_node **stack);

// Error
void			error_msg(char *str);
void			kill_process(t_stack_node **stack, char **argv, int argc);
#endif
