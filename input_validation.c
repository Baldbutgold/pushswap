/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:11:45 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/12 15:20:16 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_string_space(char *string)
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

int	check_empty_and_spaces(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || check_string_space(av[i]) == 1)
			return (ft_putstr_fd("Error\n", 2), FALSE);
		i++;
	}
	return (TRUE);
}

int	check_numbers_and_duplicates(char **arr)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (arr[i])
	{
		if (!check_string_characters(arr[i]) || !ft_atoi_push(arr[i]))
			return (FALSE);
		j = i + 1;
		num1 = ft_atoi(arr[i]);
		while (arr[j])
		{
			num2 = ft_atoi(arr[j]);
			if (num1 == num2)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_atoi_push(const char *nptr)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		if (num * sign > INT_MAX || (num * sign) < INT_MIN)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_string_characters(char *string)
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
		if (ft_isdigit(string[i]) == FALSE)
			return (0);
		i++;
	}
	if (only_sign == 1 && i == 1)
		return (0);
	return (1);
}