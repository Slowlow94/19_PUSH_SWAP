/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:26:06 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/30 13:07:03 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	pre_sort(t_list **head_a, t_list **head_b)
{
	set_smallest(head_a);
	is_above_middle(head_a);
	if (ft_lc_size(*head_a) <= 100)
		pre_sort_100(head_a, head_b);
	else
		pre_sort_500(head_a, head_b);
}

void	pre_sort_100(t_list **head_a, t_list **head_b)
{
	int		i;
	int		chunk;
	int		thresholds[3];
	int		cur_threshold;

	cur_threshold = 0;
	chunk = (ft_lc_size(*head_a) / 3);
	thresholds[0] = chunk - 1;
	thresholds[1] = (chunk * 2) - 1;
	thresholds[2] = (chunk * 3) - 1;
	i = 0;
	while (cur_threshold <= 2)
	{
		while (head_a && i <= thresholds[cur_threshold])
		{
			if ((*head_a)->new_val <= thresholds[cur_threshold])
			{
				top_a_to_top_b(head_a, head_b);
				i++;
			}
			else
				top_to_bottom_a(head_a);
		}
		cur_threshold++;
	}
}

void	pre_sort_500(t_list **head_a, t_list **head_b)
{
	int		thresholds[4];
	int		i;
	int		cur_threshold;

	cur_threshold = 0;
	thresholds[0] = (ft_lc_size(*head_a) / 4) - 1;
	thresholds[1] = ((ft_lc_size(*head_a) / 4) * 2) - 1;
	thresholds[2] = ((ft_lc_size(*head_a) / 4) * 3) - 1;
	thresholds[3] = ((ft_lc_size(*head_a) / 4) * 4) - 1;
	i = 0;
	while (cur_threshold <= 3)
	{
		while (head_a && i <= thresholds[cur_threshold])
		{
			if ((*head_a)->new_val <= thresholds[cur_threshold])
			{
				top_a_to_top_b(head_a, head_b);
				i++;
			}
			else
				top_to_bottom_a(head_a);
		}
		cur_threshold++;
	}
}
