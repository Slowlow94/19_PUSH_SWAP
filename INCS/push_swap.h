/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:45:31 by salowie           #+#    #+#             */
/*   Updated: 2023/08/14 13:35:40 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>

// typedef struct	s_ps
// {
// 	t_stack A;
// 	t_stack B;
// }					t_ps;

// typedef struct	s_stack
// {
// 	t_list **list;
// 	int size;
// 	t_list tail;
// }					t_stack;

typedef struct	s_list
{
	int				*c; // enlever le pointeur !
	struct s_list	*next;
}					t_list;

int			ft_print_stack_a(t_list **head_a); // pour tester la stack

// INITIALISATION //f
int		parse_and_create_linkchain(t_list **head_a, int argc, char **argv);
int		fill_linkchain(t_list **head_a, char **argv, int i);
long	ft_atoi(const char *str);
int		is_num(char *str);
int		is_dubble(t_list *head_A, int value);

// LINKED CHAIN UTILS //
t_list	*ft_lstnew(int *content);
t_list	*ft_lstlast(t_list *lst, int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

// ACTIONS SORT // 
void	swap(t_list **head);
void	swap_both(t_list **head_a, t_list **head_b);
void	bottom_to_top(t_list **head);
void	bottom_to_top_both(t_list **head_a, t_list **head_b);
void	top_to_bottom(t_list **head);
void	top_to_bottom_both(t_list **head_a, t_list **head_b);
void	top_to_top(t_list **head_1, t_list **head_2);

// SORT //
void	wich_sort(t_list **head_a, t_list **head_b);
void	sort_3(t_list **head_a);
void	sort_5(t_list **head_a, t_list **head_b);
int		is_min_on_bottom(t_list **head_a);
int		is_min_on_top(t_list **head_a);
void	sort(t_list **head_a, t_list **head_b);

// ERRORS //
int		ft_error(void);

#endif