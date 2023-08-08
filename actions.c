/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:14:37 by salowie           #+#    #+#             */
/*   Updated: 2023/08/08 18:42:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	swap(t_list **head)
{
	t_list *first;
	t_list *second;
	// t_ps data;

	// data->a.stacklist->content = 0;
	first = NULL;
	second = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next; // le 1er noeud pointe sur le 3eme noeud
	second->next = first; // le 2eme noeud pointe sur le 1er
	*head = second;
}

void	bottom_to_top(t_list **head)
{
	t_list *first;
	t_list *last;
	t_list *previous_to_last;

	first = NULL;
	last = NULL;
	previous_to_last = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_lstlast(*head, 0);
	previous_to_last = ft_lstlast(*head, 1);
	previous_to_last->next = NULL;
	last->next = first;
	*head = last;
}

void	top_to_bottom(t_list **head)
{
	t_list *first;
	t_list *current;

	first = NULL;
	current = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	*head = first->next;
	current = ft_lstlast(*head, 0);
	current->next = first;
	first->next = NULL;
}

void	top_to_top(t_list **head_1, t_list **head_2)
{
	t_list *first_a;

	first_a = NULL;
	if (*head_1 == NULL)
		return ;
	first_a = *head_1;
	*head_1 = first_a->next;
	first_a->next = *head_2;
	*head_2 = first_a;
}
