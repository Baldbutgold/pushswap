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

/* ----- CONSTANTS ----- */
# define TRUE 1
# define FALSE 0

/* ----- STRUCTURES ----- */
typedef struct s_list
{
	int				data;
	int				index;
	int				rank;
	struct s_list	*next;
}					t_list;

/* ----- INPUT VALIDATION FUNCTIONS ----- */
int					check_string_characters(char *string);
int					check_string_space(char *string);
int					check_empty_and_spaces(char **av);
int					check_numbers_and_duplicates(char **arr);
char				**return_string(int ac, char **av);
int					ft_atoi_push(const char *str);
void				free_grid(char **grid);

/* ----- LINKED LIST UTILITIES ----- */
t_list				*ft_lstnew(int data);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);
void				ft_printlst(t_list *head);

/* ----- STACK OPERATIONS ----- */
t_list				*init_stack(int ac, char **av);
t_list				*array_to_linked_list(char **arr);
void				assign_ranks(t_list *stack);
int					get_max_bits(t_list *stack);

#endif