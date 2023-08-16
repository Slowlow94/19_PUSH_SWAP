/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_nodes_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:07:36 by salowie           #+#    #+#             */
/*   Updated: 2023/08/16 15:46:23 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

t_list *the_cheapest(t_list **head_b)
{
	t_list *b;

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
	t_list *b;
	t_list *lowcost;

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
		// ft_printf("%d est lowcost ? : %d\n", b->c, b->lowcost);
		b = b->next;
	}
}

void	how_much(t_list **head_b, t_list **head_a)
{
	t_list *b;
	int	size_a;
	int	size_b;

	b = NULL;
	b = *head_b;
	size_a = ft_lstsize(*head_a);
	size_b = ft_lstsize(*head_b);
	while (b)
	{
		if (b->above_middle && (b->target)->above_middle)
		{
			b->price = b->position + (b->target)->position;
			// ft_printf("1. Nombre et target au dessus : %d, prix : [%d]\n", b->c, b->price);
			// ft_printf("Target : %d\n", b->target->c);
		}
		else if (b->above_middle && !((b->target)->above_middle))
		{
			b->price = b->position + (size_a - (b->target)->position);
			// ft_printf("2. Nombre au dessus et target en dessous : %d, prix : [%d]\n", b->c, b->price);
			// ft_printf("Target : %d\n", b->target->c);
		}
		else if (!(b->above_middle) && (b->target)->above_middle)
		{
			b->price = (size_b - b->position) + (b->target)->position;
			// ft_printf("3. Nombre en dessous et target au dessus : %d, prix : [%d]\n", b->c, b->price);
			// ft_printf("Target : %d\n", b->target->c);
		}
		else //if (!(b->above_middle) && !(b->target->above_middle))
		{
			b->price = (size_b - b->position) + (size_a - (b->target)->position);
			// ft_printf("4. Nombre en dessous et target en dessous : %d, prix : [%d]\n", b->c, b->price);
			// ft_printf("Target : %d\n", b->target->c);
		}
		b = b->next;
	}
}

void	is_above_middle(t_list **head)
{
	int	middle;
	t_list *stack;

	stack = NULL;
	stack = *head;
	middle = ft_lstsize(*head) / 2;
	while (stack)
	{
		if (stack->position <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		// ft_printf("Le nombre %d est %d\n", stack->c, stack->above_middle);
		stack = stack->next;
	}
}

void	give_position(t_list **head_a, t_list **head_b)
{
	int	i;
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	a = *head_a;
	b = *head_b;
	i = 0;
	while (a)
	{
		a->position = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->position = i;
		i++;
		b = b->next;
	}
}

void	find_target_node(t_list **head_a, t_list **head_b)
{
	t_list *target_node;
	t_list *a;
	t_list *b;
	int biggest_value;

	a = NULL;
	b = NULL;
	b = *head_b;
	while (b)
	{
		biggest_value = INT_MAX;
		target_node = NULL;
		a = *head_a;
		while (a)
		{
			if ((a->c > b->c) && a->c < biggest_value)
			{
				biggest_value = a->c;
				target_node = a;
			}
			a = a->next;
		}
		if (biggest_value == INT_MAX)
			b->target = find_smallest(head_a, b->c);
		else
			b->target = target_node;
		b = b->next;
	}
}

t_list *find_smallest(t_list **head_a, int value_b)
{
	int smallest_value;
	t_list *target_node;
	t_list *a;

	a = NULL;
	a = *head_a;
	smallest_value = value_b;
	while (a)
	{
		if (a->c < value_b && a->c < smallest_value)
		{
			smallest_value = a->c;
			target_node = a;
		}
		a = a->next;
	}
	return (target_node);
}