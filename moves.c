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

void	ft_printlst(t_list *head)
{
	t_list *ptr;

	ptr = head;
	while (ptr)
	{
		ft_printf("%d", ptr->rank);
		ptr = ptr->next;
	}
}

//review this function
void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !*lst)
		return;
	
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current);  // No need to free data since it's an int, not a pointer
		current = temp;
	}
	*lst = NULL;
}

t_list *array_to_linked_list(char **arr)
{
	t_list *stack;
	t_list *tail;
	t_list *new_node;
	int num;
	int i;
	
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

t_list *ft_lstnew(int data)
{
	t_list *new;
	
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

	if (!stack)
		return (0);
	
	current = stack;
	max_rank = current->rank;
	
	// Find the maximum rank in the list
	while (current)
	{
		if (current->rank > max_rank)
			max_rank = current->rank;
		current = current->next;
	}
	
	// Count the number of bits needed for the max_rank
	max_bits = 0;
	int temp = max_rank;
	while (temp > 0)
	{
		temp /= 2;  // Divide by 2 instead of bit shifting
		max_bits++;
	}
	
	return (max_bits);
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!lst || !new)
// 		return;
	
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return;
// 	}
	
// 	last = *lst;
// 	while (last->next)
// 		last = last->next;
	
// 	last->next = new;
// }

/*int	main()*/
/*	t_list *head = NULL;*/
/*	head = malloc(sizeof(t_list));*/
/*	head->data = 0;*/
/*	head->next = NULL;*/
/*	t_list *ptr = NULL;*/
/*	ptr = malloc(sizeof(t_list));*/
/*	ptr = head;*/
/*	ptr = add_to_end_of_node(ptr, 10);*/
/*	ptr = add_to_end_of_node(ptr, 20);*/
/*	add_to_node(head, 30);*/
/*	add_to_point_of_node(head, 5, 40);*/
/*	add_to_point_of_node(head, 6, 50);*/
/*	delete_last_node(head);*/
/*	print_nodes(head);*/
/*}*/