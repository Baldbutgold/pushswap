#include "push_swap.h"
#include "libft/libft.h"

static int	check_empty_and_spaces(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || check_string_space(av[i]) == 1)
			return (ft_putstr_fd("Error\n", 2), FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_numbers_and_duplicates(char **arr)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (arr[i])
	{
		if (!check_string_characters(arr[i]) || !ft_atoi_push(arr[i]))
			return (FALSE);
		j = i + 1;
		num1 = ft_atoi_push(arr[i]);
		while (arr[j])
		{
			num2 = ft_atoi_push(arr[j]);
			if (num1 == num2)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

char	**init_check(int ac, char **av)
{
	char	**arr;

	if (!check_empty_and_spaces(av))
		return (NULL);
	arr = return_string(ac, av);
	if (!arr)
		return (NULL);
	if (!check_numbers_and_duplicates(arr))
	{
		free_grid(arr);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (arr);
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