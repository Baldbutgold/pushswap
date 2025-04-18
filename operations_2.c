/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:53:44 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/12 15:53:52 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa: swap first two elements of stack a
void	sa(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	write(1, "sa\n", 3);
}

// sb: swap first two elements of stack b
void	sb(t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	write(1, "sb\n", 3);
}

// rra: reverse rotate stack a (shift down)
void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = *stack_a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "rra\n", 4);
}

// rrb: reverse rotate stack b (shift down)
void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	last = *stack_b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "rrb\n", 4);
}
