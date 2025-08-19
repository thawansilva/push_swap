/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:19:41 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/18 19:19:41 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

static int has_double_number(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_number(char *str)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	if ((str[0] == '-' && size > 11) || size > 10 || size == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_valid_numbers(char *str)
{
	char	**arr;
	int		size;

	arr = ft_split(str, ' ');
	size = 0;
	while (arr[size])
	{
		if (!is_valid_number(arr[size]))
			return (0);
		size++;
	}
	free_arr(arr);
	return (1);
}

static void	terminate_process(int argc, char **argv)
{
	if (argc == 2)
		free_arr(argv);
	error_msg("Error\n");
}

void	input_validate(int argc, char **argv)
{
	int		i;
	char	**tmp_argv;

	if (argc == 2)
		tmp_argv = ft_split(argv[1], ' ');
	else
		tmp_argv = argv + 1;
	if (has_double_number(tmp_argv))
		terminate_process(argc, tmp_argv);
	i = 0;
	while (tmp_argv[i])
	{
		if (!has_valid_numbers(tmp_argv[i]) || !is_valid_number(tmp_argv[i]))
			terminate_process(argc, tmp_argv);
		i++;
	}
	if (argc == 2)
		free_arr(tmp_argv);
}
