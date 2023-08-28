/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:14:37 by salowie           #+#    #+#             */
/*   Updated: 2023/08/28 18:22:04 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	swap_a(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = NULL;
	second = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	// stock_actions(sa);
	ft_printf("sa\n");
}

void	swap_b(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = NULL;
	second = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	// stock_actions(sb);
	ft_printf("sb\n");
}

void	bottom_to_top_a(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*previous_to_last;

	first = NULL;
	last = NULL;
	previous_to_last = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_lc_last(*head, 0);
	previous_to_last = ft_lc_last(*head, 1);
	previous_to_last->next = NULL;
	last->next = first;
	*head = last;
	// stock_actions(rra);
	ft_printf("rra\n");
}

void	bottom_to_top_b(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*previous_to_last;

	first = NULL;
	last = NULL;
	previous_to_last = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_lc_last(*head, 0);
	previous_to_last = ft_lc_last(*head, 1);
	previous_to_last->next = NULL;
	last->next = first;
	*head = last;
	// stock_actions(rrb);
	ft_printf("rrb\n");
}

void	top_to_bottom_a(t_list **head)
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
	// stock_actions(ra);
	ft_printf("ra\n");
}
