#include "push_swap.h"

void	free_grid(char **grid)
{
	int	i;
	if (!grid)
		return ;
	i = 0;
	while (grid[i])
		i++;
	while (i >= 0)
	{
		free(grid[i]);
		i--;
	}
	free(grid);
	return ;
}
