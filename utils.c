/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:07:36 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/07 12:07:44 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**return_string(int ac, char **av)
{
	char		*numbers;
	char		*temp;
	char		**arr;
	int			i;

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
int	check_string_space(char	*string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (ft_isspace(string[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_string_characters(char	*string)
{
	int	i;
	int	only_sign;

	i = 0;
	only_sign = 0;
	if (string[i] == '-' || string[i] == '+')
	{
		i++;
		only_sign = 1;
	}
	while (string[i])
	{
		if (ft_isdigit(string[i]) == 0)
			return (0);
		i++;
	}
	if (only_sign == 1 && i == 1)
		return (0);
	return (1);
}
