/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:59:33 by salowie           #+#    #+#             */
/*   Updated: 2023/08/30 13:00:24 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	both_below(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->pos > 0 && lowcost->target->pos > 0)
	{
		bottom_to_top_both(head_a, head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->pos > 0)
	{
		bottom_to_top_a(head_a);
		give_position(head_a, head_b);
	}
	while (lowcost->pos > 0)
	{
		bottom_to_top_b(head_b);
		give_position(head_a, head_b);
	}
}

void	low_below_target_am(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->pos > 0)
	{
		bottom_to_top_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->pos > 0)
	{
		top_to_bottom_a(head_a);
		give_position(head_a, head_b);
	}
}

void	low_am_target_below(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->pos > 0)
	{
		if (lowcost->pos == 1)
			swap_b(head_b);
		else
			top_to_bottom_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->pos > 0)
	{
		bottom_to_top_a(head_a);
		give_position(head_a, head_b);
	}
}

void	both_above_middle(t_list **head_a, t_list **head_b, t_list *lowcost)
{
	while (lowcost->pos > 0 && lowcost->target->pos > 0)
	{
		top_to_bottom_both(head_a, head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->pos > 0)
	{
		if (lowcost->pos == 1)
			swap_b(head_b);
		else
			top_to_bottom_b(head_b);
		give_position(head_a, head_b);
	}
	while (lowcost->target->pos > 0)
	{
		top_to_bottom_a(head_a);
		give_position(head_a, head_b);
	}
}
