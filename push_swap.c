#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;
	char	**arr;

	if (ac == 2)
		ft_printf("got two my g");
	else if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			arr = ft_split(av[i++], ' ');
			while (arr[j])
			{
				ft_printf("arr : %s \n%d, j is %d" , arr[j], ft_atoi_ps(arr[j]), j);
				j++;
			}
		}
	}
	else
	{
		ft_printf("Wrong args");
	}
}
