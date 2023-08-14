/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:31:18 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/14 19:20:26 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	sort(t_list **head_a, t_list **head_b)
{
	while (ft_lstsize(*head_a) > 3)
		top_to_top(head_a, head_b);
	sort_3(head_a);
}
