/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:26:06 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/22 21:53:40 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	pre_sort(t_list **head_a, t_list **head_b)
{
	set_smallest(head_a);
	is_above_middle(head_a);
	if (ft_lstsize(*head_a) <= 100)
		pre_sort_100(head_a, head_b);
	else
		pre_sort_500(head_a, head_b);
}

void pre_sort_100(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int thresholds[] = {33, 66, 96};
    int current_threshold = 0;

    temp = *head_a;
    while (temp && current_threshold < 3)
    {
        if (temp->new_val <= thresholds[current_threshold])
        {
            put_stack_in_order(head_a, temp, 'a');
            top_a_to_top_b(head_a, head_b);
            temp = *head_a;
        }
        else
            current_threshold++;
    }
}

void pre_sort_500(t_list **head_a, t_list **head_b)
{
    t_list *temp;
    int thresholds[] = {125, 250, 375, 496};
    int current_threshold = 0;

    temp = *head_a;
    while (temp && current_threshold < 4)
    {
        if (temp->new_val <= thresholds[current_threshold])
        {
            put_stack_in_order(head_a, temp, 'a');
            top_a_to_top_b(head_a, head_b);
            temp = *head_a;
        }
        else
            current_threshold++;
    }
}

void	set_smallest(t_list **head_a)
{
	t_list *min;
	t_list *current;
	int new_value;
	int	size;

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

void	set_new_val_done(t_list **head_a)
{
	t_list *temp;

	temp = NULL;
	temp = *head_a;
	while (temp)
	{
		temp->new_val_done = 0;
		temp->new_val = 0;
		temp = temp->next;
	}
}
