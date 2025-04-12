#include "push_swap.h"

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

t_list	*init_stack(int ac, char **av)
{
	t_list	*stack_a;
	char	**arr;

	if (ac < 2)
		return (NULL);
	arr = init_check(ac, av);
	if (!arr)
		return (NULL);
	stack_a = array_to_linked_list(arr);
	free_grid(arr);
	assign_ranks(stack_a);
	return (stack_a);
}
char	**init_check(int ac, char **av)
{
	char	**arr;

	if (!check_empty_and_spaces(av))
		return (NULL);
	arr = return_string(ac, av);
	if (!arr)
		return (NULL);
		//error is here for zero
	if (!check_numbers_and_duplicates(arr))
	{
		free_grid(arr);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (arr);
}

void	assign_ranks(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		rank;

	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (current->data > compare->data)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}