/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:40:38 by salowie           #+#    #+#             */
/*   Updated: 2023/08/23 15:13:02 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	swap_both(t_list **head_a, t_list **head_b)
{
	swap_a(head_a);
	swap_b(head_b);
}

void	bottom_to_top_both(t_list **head_a, t_list **head_b)
{
	bottom_to_top_a(head_a);
	bottom_to_top_b(head_b);
}

void	top_to_bottom_both(t_list **head_a, t_list **head_b)
{
	top_to_bottom_a(head_a);
	top_to_bottom_b(head_b);
}
