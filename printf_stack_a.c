/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:17:42 by salowie           #+#    #+#             */
/*   Updated: 2023/08/07 16:27:14 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	ft_print_stack_a(t_list **head_a)
{
	int i;

	i = 0;
	while (*head_a)
	{
		ft_printf("Position %d : [%d]\n", i, *(int *)(*head_a)->content);
		*head_a = (*head_a)->next;
		i++;
	}
	return (0);
}