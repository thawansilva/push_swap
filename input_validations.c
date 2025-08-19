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

int has_double_number(char **args)
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

int	is_valid_number(char *str)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	if (size == 0)
		return (0);
	if (str[0] == '-' && size > 11)
		return (0);
	else if (size > 10)
		return (0);
	i = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	return (1);
}

void	input_validate(int argc, char **argv)
{
	// numeros não inteiros, valores que passe do int min ou max int e duplicados
	int		i;
	char	**tmp_argv;
//	long	tmp_nbr;

	if (argc == 2)
		tmp_argv = ft_split(argv[1], ' ');
	else
		tmp_argv = argv + 1;
	if (has_double_number(tmp_argv))
	{
		if (argc == 2)
			free_arr(tmp_argv);
		error_msg("Error\n");
	}
	i = 0;
	while (tmp_argv[i])
	{
//		tmp_nbr = ft_atoi(tmp_argv[i]);
		if (!is_valid_number(tmp_argv[i]))
		{
			if (argc == 2)
				free_arr(tmp_argv);
			error_msg("Error\n");
		}
		i++;
	}
	if (argc == 2)
		free_arr(tmp_argv);
}

