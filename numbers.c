/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:22:43 by thaperei          #+#    #+#             */
/*   Updated: 2025/08/19 17:22:43 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	get_count_numbers(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

static void	set_numbers(char **arr, int *arr_nbr)
{
	int	i;
	int	count_numbers;

	i = 0;
	count_numbers = get_count_numbers(arr);
	while (i < count_numbers)
	{
		arr_nbr[i] = ft_atoi(arr[i]);
		i++;
	}
}

int	*get_numbers(int argc, char **argv, int *size)
{
	char	**arr;
	int		*arr_nbr;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = argv + 1;
	*size = get_count_numbers(arr);
	arr_nbr = (int *) malloc(sizeof(int ) * *size);
	if (!arr_nbr)
	{
		if (argc == 2)
			free_arr(arr);
		error_msg("Error\n");
	}
	set_numbers(arr, arr_nbr);
	return (arr_nbr);
}
