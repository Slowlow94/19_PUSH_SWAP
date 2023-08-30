/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:08:11 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/30 13:12:16 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	top_to_bottom_b(t_list **head)
{
	t_list	*first;
	t_list	*current;

	first = NULL;
	current = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	*head = first->next;
	current = ft_lc_last(*head, 0);
	current->next = first;
	first->next = NULL;
	stock_actions(rb);
}

void	top_a_to_top_b(t_list **head_1, t_list **head_2)
{
	t_list	*first_a;

	first_a = NULL;
	if (*head_1 == NULL)
		return ;
	first_a = *head_1;
	*head_1 = first_a->next;
	first_a->next = *head_2;
	*head_2 = first_a;
	stock_actions(pb);
}

void	top_b_to_top_a(t_list **head_1, t_list **head_2)
{
	t_list	*first_a;

	first_a = NULL;
	if (*head_1 == NULL)
		return ;
	first_a = *head_1;
	*head_1 = first_a->next;
	first_a->next = *head_2;
	*head_2 = first_a;
	stock_actions(pa);
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
