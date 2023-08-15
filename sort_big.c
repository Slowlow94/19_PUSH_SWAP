/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:31:18 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/15 18:55:43 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	sort_big(t_list **head_a, t_list **head_b)
{
	while (ft_lstsize(*head_a) > 3)
		top_to_top(head_a, head_b);
	sort_3(head_a);
	while(*head_b)
	{
		find_target_node(head_a, head_b);
		give_position(head_a, head_b);
		is_above_middle(head_a);
		is_above_middle(head_b);
		how_much(head_b, head_a);
		*head_b = (*head_b)->next;
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
			ft_printf("1. Nombre et target au dessus : %d, prix : [%d]\n", b->c, b->price);
		}
		else if (b->above_middle && !((b->target)->above_middle))
		{
			b->price = b->position + (size_a - (b->target)->position);
			ft_printf("2. Nombre au dessus et target en dessous : %d, prix : [%d]\n", b->c, b->price);
		}
		else if (!(b->above_middle) && (b->target)->above_middle)
		{
			b->price = (size_b - b->position) + (b->target)->position;
			ft_printf("3. Nombre en dessous et target au dessus : %d, prix : [%d]\n", b->c, b->price);
		}
		else //if (!(b->above_middle) && !(b->target->above_middle))
		{
			b->price = (size_b - b->position) + (size_a - (b->target)->position);
			ft_printf("4. Nombre en dessous et target en dessous : %d, prix : [%d]\n", b->c, b->price);
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
		ft_printf("Le nombre %d est %d\n", stack->c, stack->above_middle);
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
	a = *head_a;
	biggest_value = INT_MAX;
	target_node = NULL;
	while (b)
	{
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
