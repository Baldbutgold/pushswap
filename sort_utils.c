/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:09:21 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/11 22:09:21 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list *stack)
{
	t_list	*current;
	int		max_rank;
	int		max_bits;
	int		temp;

	if (!stack)
		return (0);
	current = stack;
	max_rank = current->rank;
	while (current)
	{
		if (current->rank > max_rank)
			max_rank = current->rank;
		current = current->next;
	}
	max_bits = 0;
	temp = max_rank;
	while (temp > 0)
	{
		temp /= 2;
		max_bits++;
	}
	return (max_bits);
}

int	is_sorted(t_list *stack)
{
	t_list	*current;

	if (!stack || !stack->next)
		return (1);  // Empty stack or single element stack is considered sorted
	current = stack;
	while (current->next)
	{
		if (current->rank > current->next->rank)
			return (0);  // Not sorted
		current = current->next;
	}
	return (1);  // Sorted
}