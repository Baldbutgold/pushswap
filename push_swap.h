/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:09:08 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/04/07 12:09:09 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	int				d;
	struct s_list	*n;
}					t_list;

void				free_grid(char **grid);
int					check_string_characters(char *string);
int					check_string_space(char *string);
char				**return_string(int ac, char **av);

#endif
