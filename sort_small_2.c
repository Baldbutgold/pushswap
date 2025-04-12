/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:50:54 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/12 15:51:00 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_rest(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	pos;
	int	size;

	size = ft_lstsize(*stack_a);
	min = find_min_rank(*stack_a);
	pos = find_position(*stack_a, min);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack_a);
	else
		while (pos++ < size)
			rra(stack_a);
	pb(stack_a, stack_b);
	min = find_min_rank(*stack_a);
	pos = find_position(*stack_a, min);
	if (pos <= (size - 1) / 2)
		while (pos-- > 0)
			ra(stack_a);
	else
		while (pos++ < size - 1)
			rra(stack_a);
	sort_five_rest(stack_a, stack_b);
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
