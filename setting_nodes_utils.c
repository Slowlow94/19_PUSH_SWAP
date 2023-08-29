/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_nodes_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:07:36 by salowie           #+#    #+#             */
/*   Updated: 2023/08/29 17:37:04 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

t_list	*the_cheapest(t_list **head_b)
{
	t_list	*b;

	b = NULL;
	b = *head_b;
	while (b)
	{
		if (b->lowcost == true)
			return (b);
		b = b->next;
	}
	return (b);
}

void	wich_one_is_lowcost(t_list **head_b)
{
	t_list	*b;
	t_list	*lowcost;

	b = NULL;
	lowcost = NULL;
	b = *head_b;
	lowcost = b;
	while (b)
	{
		if (b->price < lowcost->price)
			lowcost = b;
		b = b->next;
	}
	b = *head_b;
	while (b)
	{
		if (b == lowcost)
			b->lowcost = true;
		else
			b->lowcost = false;
		b = b->next;
	}
}

void	how_much(t_list **head_b, t_list **head_a)
{
	t_list	*b;
	int		size_a;
	int		size_b;

	b = NULL;
	b = *head_b;
	size_a = ft_lc_size(*head_a);
	size_b = ft_lc_size(*head_b);
	while (b)
	{
		if (b->above_middle && (b->target)->above_middle)
			b->price = b->pos + (b->target)->pos;
		else if (b->above_middle && !((b->target)->above_middle))
			b->price = b->pos + (size_a - (b->target)->pos);
		else if (!(b->above_middle) && (b->target)->above_middle)
			b->price = (size_b - b->pos) + (b->target)->pos;
		else
			b->price = (size_b - b->pos) + (size_a - (b->target)->pos);
		b = b->next;
	}
}

void	is_above_middle(t_list **head)
{
	int		middle;
	t_list	*stack;

	stack = NULL;
	stack = *head;
	middle = ft_lc_size(*head) / 2;
	while (stack)
	{
		if (stack->pos <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
	}
}

void	give_position(t_list **head_a, t_list **head_b)
{
	int		i;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	a = *head_a;
	b = *head_b;
	i = 0;
	while (a)
	{
		a->pos = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->pos = i;
		i++;
		b = b->next;
	}
}
