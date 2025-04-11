/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:35 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/11 22:12:07 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = init_stack(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	get_max_bits(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}