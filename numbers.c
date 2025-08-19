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

int	*get_numbers(int argc, char **argv)
{
	char	**arr;
	int		count_numbers;
	int		*arr_nbr;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = argv + 1;
	count_numbers = get_count_numbers(argv);
	arr_nbr = (int *) malloc(sizeof(int ) * count_numbers);
	if (!arr_nbr)
	{
		if (argc == 2)
			free_arr(arr);
		error_msg("Error\n");
	}
	return (arr_nbr);
}
