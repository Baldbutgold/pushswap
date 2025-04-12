/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:10:36 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/11 22:10:03 by ael-hadj         ###   ########.fr       */
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

void	ft_printlst(t_list *head)
{
	t_list	*ptr;

	ptr = head;
	while (ptr)
	{
		ft_printf("%d", ptr->rank);
		ptr = ptr->next;
	}
}
