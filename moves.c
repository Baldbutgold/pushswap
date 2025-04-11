/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:10:36 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/11 16:10:36 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}


void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*lst = NULL;
}

t_list	*array_to_linked_list(char **arr)
{
	t_list	*stack;
	t_list	*tail;
	t_list	*new_node;
	int		num;
	int		i;

	stack = NULL;
	tail = NULL;
	i = 0;
	while (arr[i])
	{
		num = ft_atoi(arr[i]);
		new_node = ft_lstnew(num);
		if (!new_node)
			return (ft_putstr_fd("Error\n", 2), ft_lstclear(&stack), NULL);
		if (!stack)
			stack = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		i++;
	}
	return (stack);
}

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

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
