#include "push_swap.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	int	i;
	char	*numbers;

	if (ac > 2)
	{
		numbers = NULL;
		i = 1;
		while (i < ac)
		{
			ft_printf("av %s", av[i]);
			ft_printf("num %s", numbers);
			numbers = ft_strjoin(numbers, av[i]);
			i++;
		}
		ft_printf("%s", numbers);
	}
}
