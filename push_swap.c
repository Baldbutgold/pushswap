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

char	**init_check(int ac, char **av)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (ft_putstr_fd("Error\n", 2), NULL);
		if (check_string_space(av[i]) == 1)
			return (ft_putstr_fd("Error\n", 2), NULL);
		i++;
	}
	arr = return_string(ac, av);
	i = 0;
	while (arr[i])
	{
		if (check_string_characters(arr[i]) == 0)
			return (free_grid(arr), ft_putstr_fd("Error\n", 2), NULL);
		j = i + 1;
		if (ft_atoi_push(arr[i]) == FALSE)
			return (free_grid(arr), ft_putstr_fd("Error\n", 2), NULL);
		while (arr[j])
		{
			if (ft_atoi_push(arr[i]) == ft_atoi_push(arr[j]))
				return (free_grid(arr), ft_putstr_fd("Error\n", 2), NULL);
			j++;
		}
		i++;
	}
	return (arr);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arr;
	int i;

	stack_a = NULL;
	stack_b = NULL;	

	if (ac > 1)
		arr = init_check(ac, av);
	else
		return (0);
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		ft_printf("%s", arr[i++]);
	free_grid(arr);
}

/*while (arr[i])*/
/*	ft_printf("%s", arr[i++]);*/
/*free_grid(arr);*/