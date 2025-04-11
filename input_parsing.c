/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:14:02 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/11 22:14:02 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**return_string(int ac, char **av)
{
	char	*numbers;
	char	*temp;
	char	**arr;
	int		i;

	numbers = ft_strdup(av[1]);
	i = 2;
	while (i < ac)
	{
		temp = numbers;
		numbers = ft_strjoin(temp, " ");
		free(temp);
		temp = numbers;
		numbers = ft_strjoin(temp, av[i++]);
		free(temp);
	}
	arr = ft_split(numbers, ' ');
	free(numbers);
	return (arr);
}