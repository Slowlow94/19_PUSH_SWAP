/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_nodes_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:52:34 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/30 10:15:27 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	find_target_node(t_list **head_a, t_list **head_b)
{
	t_list	*target_node;
	t_list	*a;
	t_list	*b;
	int		biggest_value;

	b = *head_b;
	biggest_value = INT_MAX;
	while (b)
	{
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

t_list	*find_smallest(t_list **head_a, int value_b)
{
	int		smallest_value;
	t_list	*target_node;
	t_list	*a;

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
