/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:35 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/28 09:21:35 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	main(int ac, char **av)
{
	int	i;
	int	is_error;
	char	**arr;

	is_error = 0;
	if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			if (av[i][0] == '\0')
				return (ft_putstr_fd("Error\n", 2), 0);
			if (check_string_space(av[i]) == 1)
				return (ft_putstr_fd("Error\n", 2), 0);
			i++;
		}
		arr = return_string(ac, av);
		i = 0;
		while (arr[i])
		{
			if (check_string_characters(arr[i]) == 0)
				is_error = 1;
			i++;
		}
		if (is_error == 1)
			return (free_grid(arr), ft_putstr_fd("Error\n", 2), 0);
		i = 0;
		while (arr[i])
			ft_printf("%s", arr[i++]);
		free_grid(arr);
	}
}
