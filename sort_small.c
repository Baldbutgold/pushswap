/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:00:00 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/12 10:00:00 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->rank > (*stack_a)->next->rank)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->rank;
	b = (*stack_a)->next->rank;
	c = (*stack_a)->next->next->rank;
	
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

int	find_min_rank(t_list *stack)
{
	int		min;
	t_list	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	min = tmp->rank;
	while (tmp)
	{
		if (tmp->rank < min)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

int	find_position(t_list *stack, int rank)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->rank == rank)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	pos;
	int	size;

	size = ft_lstsize(*stack_a);
	min = find_min_rank(*stack_a);
	pos = find_position(*stack_a, min);
	
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < size)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	pos;
	int	size;

	// Push smallest element to B
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
	
	// Push second smallest element to B
	min = find_min_rank(*stack_a);
	pos = find_position(*stack_a, min);
	if (pos <= (size - 1) / 2)
		while (pos-- > 0)
			ra(stack_a);
	else
		while (pos++ < size - 1)
			rra(stack_a);
	pb(stack_a, stack_b);
	
	// Sort remaining 3 elements
	sort_three(stack_a);
	
	// Push back from B to A
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
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
