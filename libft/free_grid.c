/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:53:29 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/07 10:53:36 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
