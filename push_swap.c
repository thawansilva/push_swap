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

void error_msg(char *str)
{
	ft_putstr_fd(str, STDERR);
	exit(0);
}

void free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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

void	input_validate(int argc, char **argv)
{
	// numeros não inteiros, valores que passe do int min ou max int e duplicados
	// pode receber uma string inteira como argumento
	int		i;
	char	**tmp_argv;
	//long	tmp_nbr;

	if (argc == 2)
		tmp_argv = ft_split(argv[1], ' ');
	else
		tmp_argv = argv + 1;
	i = 0;
	while (tmp_argv[i])
	{
		//tmp_nbr = ft_atoi(tmp_argv[i]);
		if (has_double_number(tmp_argv))
			error_msg("Error\n");
		//if (true)
		//{
		//	
		//}
	}
	if (argc == 2)
		free_arr(tmp_argv);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	input_validate(argc, argv);
	return 0;
}
