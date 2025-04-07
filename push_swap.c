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

int	main(int ac, char **av)
{
	int	i;

	if (ac > 2)
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
		i = 1;
		while (av[i])
			ft_printf("%s", av[i++]);
	}
}
