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

// Stack functions
void	create_stack(t_list **stack, int *numbers, int size);

// Number functions
int		*get_numbers(int argc, char **argv, int *size);

// Utils functions
void	error_msg(char *str);
void	free_arr(char **arr);
void	free_numbers(int *arr);
void	free_content(void *content);
void	free_stack(t_list **stack_a);

// Validation
void	input_validate(int argc, char **argv);
#endif
