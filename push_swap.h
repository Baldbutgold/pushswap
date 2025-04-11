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
	int				data;
	int				index;
	int				rank;
	struct s_list	*next;
}					t_list;

void				free_grid(char **grid);
int					check_string_characters(char *string);
int					check_string_space(char *string);
char				**return_string(int ac, char **av);
int					ft_atoi_push(const char *str);
void				ft_printlst(t_list *head);
void				ft_lstclear(t_list **lst);
t_list				*array_to_linked_list(char **arr);
t_list				*ft_lstnew(int data);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*init_stack(int ac, char **av);


#endif
