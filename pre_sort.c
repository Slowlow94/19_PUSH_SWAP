/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:26:06 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/24 13:32:53 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	pre_sort(t_list **head_a, t_list **head_b)
{
	set_smallest(head_a);
	is_above_middle(head_a);
	if (ft_lstsize(*head_a) == 100)
		pre_sort_100(head_a, head_b);
	else if (ft_lstsize(*head_a) == 500)
		pre_sort_500(head_a, head_b);
	else
		return ;
}

void	pre_sort_100(t_list **head_a, t_list **head_b)
{
	int		i;
	int		current_threshold;
	int		thresholds[3];

	thresholds[0] = 33;
	thresholds[1] = 66;
	thresholds[2] = 96;
	current_threshold = 0;
	i = 0;
	while (head_a && current_threshold < 3 && i < ((current_threshold + 1) * 33))
	{
		if ((*head_a)->new_val <= thresholds[current_threshold])
		{
			top_a_to_top_b(head_a, head_b);
			maybe_ss(head_a, head_b);
			i++;
		}
		else
			top_to_bottom_a(head_a);
	}
	current_threshold++;
}

void	pre_sort_500(t_list **head_a, t_list **head_b)
{
	int		thresholds[4];
	int		current_threshold;
	int		i;

	thresholds[0] = 125;
	thresholds[1] = 250;
	thresholds[2] = 375;
	thresholds[3] = 496;
	current_threshold = 0;
	i = 0;
	while (head_a && current_threshold < 4 && i < ((current_threshold + 1) * 125))
	{
		if ((*head_a)->new_val <= thresholds[current_threshold])
		{
			top_a_to_top_b(head_a, head_b);
			maybe_ss(head_a, head_b);
			i++;
		}
		else
			top_to_bottom_a(head_a);
	}
	current_threshold++;

}

void	maybe_ss(t_list **head_a, t_list **head_b)
{
	t_list	*a;
	t_list	*b;

	if (!head_a || !head_b || !(*head_b)->next || !(*head_a)->next)
		return ;
	a = NULL;
	a = *head_a;
	b = NULL;
	b = *head_b;
	if (a->new_val > a->next->new_val && b->new_val > b->next->new_val)
		swap_both(head_a, head_b);
}

void	set_smallest(t_list **head_a)
{
	t_list	*min;
	t_list	*current;
	int		new_value;
	int		size;

	size = ft_lstsize(*head_a);
	new_value = 0;
	set_new_val_done(head_a);
	while (new_value < size)
	{
		current = *head_a;
		min = NULL;
		while (current)
		{
			if (!current->new_val_done && (!min || current->c < min->c))
				min = current;
			current = current->next;
		}
		if (min)
		{
			min->new_val = new_value;
			min->new_val_done = 1;
			new_value++;
		}
	}
}
