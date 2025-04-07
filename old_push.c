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

int	main(int ac, char **av)
{
	char **arr;

	if (ac > 2)
	{
		arr = return_string(ac, av);
		int i = 0;
		while (arr[i])
			ft_printf("%s",arr[i++]);
		free_grid(arr);
	}
}
