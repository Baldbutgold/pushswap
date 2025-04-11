/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:07:36 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/07 12:07:44 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char	**return_string(int ac, char **av)
{
	char		*numbers;
	char		*temp;
	char		**arr;
	int			i;

	numbers = ft_strdup(av[1]);
	i = 2;
	while (i < ac)
	{
		temp = numbers;
		numbers = ft_strjoin(temp, " ");
		free(temp);
		temp = numbers;
		numbers = ft_strjoin(temp, av[i++]);
		free(temp);
	}
	arr = ft_split(numbers, ' ');
	free(numbers);
	return (arr);
}

int	check_string_space(char	*string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (ft_isspace(string[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_string_characters(char	*string)
{
	int	i;
	int	only_sign;

	i = 0;
	only_sign = 0;
	if (string[i] == '-' || string[i] == '+')
	{
		i++;
		only_sign = 1;
	}
	while (string[i])
	{
		if (ft_isdigit(string[i]) == 0)
			return (0);
		i++;
	}
	if (only_sign == 1 && i == 1)
		return (0);
	return (1);
}

// Function to count nodes in a linked list
static int  ft_lstsize(t_list *lst)
{
    int size;

    size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}

// Function to assign ranks to stack elements
void    assign_ranks(t_list *stack)
{
    t_list  *current;
    t_list  *compare;
    int     size;
    int     rank;

    size = ft_lstsize(stack);
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