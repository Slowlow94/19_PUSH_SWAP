/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:17:42 by salowie           #+#    #+#             */
/*   Updated: 2023/08/15 11:00:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

int	ft_print_stack_a(t_list **head_a)
{
	int i;
	t_list *first;

	first = NULL;
	first = *head_a;
	i = 0;
	while (first)
	{
		ft_printf("Position %d : [%d]\n", i, (first)->c);
		first = first->next;
		i++;
	}
	return (0);
}