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
		i++;
	}
	return (arr);
}

int	main(int ac, char **av)
{
	char	**arr;
	int i;

	if (ac > 1)
		arr = init_check(ac, av);
	else
		return (0);
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		ft_printf("%s", arr[i++]);
}

/*while (arr[i])*/
/*	ft_printf("%s", arr[i++]);*/
/*free_grid(arr);*/
