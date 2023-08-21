/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:45:31 by salowie           #+#    #+#             */
/*   Updated: 2023/08/21 10:07:13 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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
	int				c;
	int				price;
	int				position;
	bool			above_middle;
	bool			lowcost;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

int		ft_print_stack_a(t_list **head_a); // pour tester la stack

// INITIALISATION //
int		parse_and_create_linkchain(t_list **head_a, int argc, char **argv);
int		fill_linkchain(t_list **head_a, char **argv, int i);
long	ft_atoi(const char *str);
int		is_num(char *str);
int		is_dubble(t_list **head_A, int value);

// LINKED CHAIN UTILS //
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst, int i);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

// ACTIONS SORT // 
void	swap_a(t_list **head);
void	swap_b(t_list **head);
void	swap_both(t_list **head_a, t_list **head_b);
void	bottom_to_top_a(t_list **head);
void	bottom_to_top_b(t_list **head);
void	bottom_to_top_both(t_list **head_a, t_list **head_b);
void	top_to_bottom_a(t_list **head);
void	top_to_bottom_b(t_list **head);
void	top_to_bottom_both(t_list **head_a, t_list **head_b);
void	top_a_to_top_b(t_list **head_1, t_list **head_2);
void	top_b_to_top_a(t_list **head_1, t_list **head_2);

// SORT //
void	wich_sort(t_list **head_a, t_list **head_b);
void	sort_3(t_list **head_a);
void	sort_5(t_list **head_a, t_list **head_b);
void	sort_big(t_list **head_a, t_list **head_b);

// SORT_UTILS FOR SORT_5 //
int		is_min_on_bottom(t_list **head_a);
int		is_min_on_top(t_list **head_a);
void	setting_nodes(t_list **head_a, t_list **head_b);
void	move_nodes(t_list **head_a, t_list **head_b);

// SORT_UTILS FOR SORT_BIG //
void	find_target_node(t_list **head_a, t_list **head_b);
t_list	*find_smallest(t_list **head_a, int value_b);
void	give_position(t_list **head_a, t_list **head_b);
void	how_much(t_list **head_b, t_list **head_a);
void	is_above_middle(t_list **head);
void	wich_one_is_lowcost(t_list **head_b);
t_list	*the_cheapest(t_list **head_b);

// MOVE_NODES UTILS //
void	both_above_middle(t_list **head_a, t_list **head_b, t_list *lowcost);
void	low_am_target_below(t_list **head_a, t_list **head_b, t_list *lowcost);
void	low_below_target_am(t_list **head_a, t_list **head_b, t_list *lowcost);
void	both_below(t_list **head_a, t_list **head_b, t_list *lowcost);
void	put_stack_in_order(t_list **head, t_list *become_top, char c);
t_list	*return_min(t_list **head_a);

// ERRORS //
int		ft_error(void);

#endif