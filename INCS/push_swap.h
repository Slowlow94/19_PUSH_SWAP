/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:45:31 by salowie           #+#    #+#             */
/*   Updated: 2023/08/28 17:10:39 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef enum op
{
	op_NULL,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
}	t_op;

typedef struct s_list
{
	int				c;
	enum op			ope;
	int				price;
	int				new_val;
	int				pos;
	bool			above_middle;
	bool			lowcost;
	bool			new_val_done;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

// INITIALISATION //
int		parse_and_create_linkchain(t_list **head_a, int argc, char **argv);
int		fill_linkchain(t_list **head_a, char **argv, int i);
int		is_num(char *str);
int		is_dubble(t_list **head_A, int value);
long	ft_atoi(const char *str);

// ERRORS //
int		ft_error(void);

// LINKED CHAIN UTILS //
void	ft_lc_add_back(t_list **lst, t_list *new);
void	ft_lc_clear(t_list **lst);
void	deleteone(t_list **lst);
int		ft_lc_size(t_list *lst);
t_list	*ft_lc_new(int content);
t_list	*ft_lc_new_enum(t_op ope);
t_list	*ft_lc_last(t_list *lst, int i);

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
void	give_position(t_list **head_a, t_list **head_b);
void	how_much(t_list **head_b, t_list **head_a);
void	is_above_middle(t_list **head);
void	wich_one_is_lowcost(t_list **head_b);
t_list	*find_smallest(t_list **head_a, int value_b);
t_list	*the_cheapest(t_list **head_b);

// MOVE_NODES UTILS //
void	both_above_middle(t_list **head_a, t_list **head_b, t_list *lowcost);
void	low_am_target_below(t_list **head_a, t_list **head_b, t_list *lowcost);
void	low_below_target_am(t_list **head_a, t_list **head_b, t_list *lowcost);
void	both_below(t_list **head_a, t_list **head_b, t_list *lowcost);
void	put_stack_in_order(t_list **head, t_list *become_top, char c);
t_list	*return_min(t_list **head_a);

// PRE_SORT //
void	pre_sort(t_list **head_a, t_list **head_b);
void	set_smallest(t_list **head_a);
void	set_new_val_done(t_list **head_a);
void	pre_sort_100(t_list **head_a, t_list **head_b);
void	pre_sort_500(t_list **head_a, t_list **head_b);
void	maybe_ss(t_list **head_a, t_list **head_b);

// POST_SORT // 
void	stock_actions(t_op ope);
void	sort_opti(t_list **move_list);
void	replace_move(t_list **move_list, int pos, t_op ope);
void	give_position_opti(t_list **head);
void	print_action_list(t_list **move_list);
void	init_moves_list(t_op ope);
t_list	**get_moves_list(void);

int	ft_print_stack_a(t_list **head_a); // !!!!!!!!!!!!!!!!!
#endif