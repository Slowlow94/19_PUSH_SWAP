/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:28:53 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/30 13:07:19 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	set_new_val_done(t_list **head_a)
{
	t_list	*temp;

	temp = NULL;
	temp = *head_a;
	while (temp)
	{
		temp->new_val_done = 0;
		temp->new_val = 0;
		temp = temp->next;
	}
}

void	set_smallest(t_list **head_a)
{
	t_list	*min;
	t_list	*current;
	int		new_value;
	int		size;

	size = ft_lc_size(*head_a);
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
