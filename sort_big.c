/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:31:18 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/21 10:11:15 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	sort_big(t_list **head_a, t_list **head_b)
{
	while (ft_lstsize(*head_a) > 3)
		top_a_to_top_b(head_a, head_b);
	sort_3(head_a);
	while(*head_b)
	{
		setting_nodes(head_a, head_b);
		move_nodes(head_a, head_b);
	}
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
	t_list *lowcost;
	t_list *first;
	t_list *last;

	first = NULL;
	last = NULL;
	last = ft_lstlast(*head_a, 0);
	first = *head_a;
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
	put_stack_in_order(head_b, lowcost, 'b');
	put_stack_in_order(head_a, lowcost->target, 'a');
	top_b_to_top_a(head_b, head_a);
	if (!(first == lowcost->target) && !(last == lowcost->target))
	{
		put_stack_in_order(head_a, return_min(head_a), 'a');
		// ft_printf("head_a : %d, target de lowcost : %d\n", (*head_a)->c, lowcost->target->c);
	}
}

t_list *return_min(t_list **head_a)
{
	t_list *min;
	t_list *current;

	min = NULL;
	current = NULL;
	min = *head_a;
	current = *head_a;
	while (current)
	{
		if (current->c < min->c)
		{
			min = current;
			// ft_printf("Min in while : %d\n", min->c);
		}
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

void	both_below(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->position > 0)
	{
		bottom_to_top_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->position > 0)
	{
		bottom_to_top_a(head_a);
		give_position(head_a, head_b);
	}
}

void	low_below_target_am(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->position > 0)
	{
		bottom_to_top_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->position > 0)
	{
		top_to_bottom_a(head_a);
		give_position(head_a, head_b);
	}
}

void	low_am_target_below(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->position > 0)
	{
		if(lowcost->position == 1)
			swap_b(head_b);
		else
			top_to_bottom_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->position > 0)
	{
		bottom_to_top_a(head_a);
		give_position(head_a, head_b);
	}
}

void	both_above_middle(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->position > 0)
	{
		if(lowcost->position == 1)
			swap_b(head_b);
		else
			top_to_bottom_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->position > 0)
	{
		top_to_bottom_a(head_a);
		give_position(head_a, head_b);
	}
}
