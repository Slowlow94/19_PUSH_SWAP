/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:31:18 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/24 12:55:59 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	sort_big(t_list **head_a, t_list **head_b)
{
	pre_sort(head_a, head_b);
	while (ft_lstsize(*head_a) > 3)
		top_a_to_top_b(head_a, head_b);
	sort_3(head_a);
	while (*head_b)
	{
		setting_nodes(head_a, head_b);
		move_nodes(head_a, head_b);
	}
	put_stack_in_order(head_a, return_min(head_a), 'a');
}

void	setting_nodes(t_list **head_a, t_list **head_b)
{
	find_target_node(head_a, head_b);
	give_position(head_a, head_b);
	is_above_middle(head_a);
	is_above_middle(head_b);
	how_much(head_b, head_a);
	wich_one_is_lowcost(head_b);
}

void	move_nodes(t_list **head_a, t_list **head_b)
{
	t_list	*lowcost;
	int		var1;

	lowcost = NULL;
	lowcost = the_cheapest(head_b);
	if (lowcost->above_middle && lowcost->target->above_middle)
		both_above_middle(head_a, head_b, lowcost);
	else if (lowcost->above_middle && !(lowcost->target->above_middle))
		low_am_target_below(head_a, head_b, lowcost);
	else if (!(lowcost->above_middle) && lowcost->target->above_middle)
		low_below_target_am(head_a, head_b, lowcost);
	else
		both_below(head_a, head_b, lowcost);
	setting_nodes(head_a, head_b);
	var1 = put_stack_in_order_simulation(head_b, lowcost, 'b');
	if (var1 == put_stack_in_order_simulation(head_a, lowcost->target, 'a'))
	{
		if (var1 == 1)
			top_to_bottom_both(head_a, head_b);
		else
			bottom_to_top_both(head_a, head_b);
	}
	else
	{
		put_stack_in_order(head_b, lowcost, 'b');
		put_stack_in_order(head_a, lowcost->target, 'a');
	}
	top_b_to_top_a(head_b, head_a);
}

t_list	*return_min(t_list **head_a)
{
	t_list	*min;
	t_list	*current;

	min = NULL;
	current = NULL;
	min = *head_a;
	current = *head_a;
	while (current)
	{
		if (current->c < min->c)
			min = current;
		current = current->next;
	}
	return (min);
}

void	put_stack_in_order(t_list **head, t_list *become_top, char c)
{
	while (*head != become_top)
	{
		if (c == 'a')
		{
			if (become_top->above_middle)
				top_to_bottom_a(head);
			else
				bottom_to_top_a(head);
		}
		else
		{
			if (become_top->above_middle)
				top_to_bottom_b(head);
			else
				bottom_to_top_b(head);
		}
	}
}
