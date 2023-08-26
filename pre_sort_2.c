/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:28:53 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/24 13:29:56 by Sarah            ###   ########.fr       */
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
