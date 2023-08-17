/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:14:37 by salowie           #+#    #+#             */
/*   Updated: 2023/08/17 15:19:22 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	swap_a(t_list **head)
{
	t_list *first;
	t_list *second;
	first = NULL;
	second = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next; // le 1er noeud pointe sur le 3eme noeud
	second->next = first; // le 2eme noeud pointe sur le 1er
	*head = second;
	ft_printf("swap_a\n");
}

void	swap_b(t_list **head)
{
	t_list *first;
	t_list *second;
	first = NULL;
	second = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next; // le 1er noeud pointe sur le 3eme noeud
	second->next = first; // le 2eme noeud pointe sur le 1er
	*head = second;
	ft_printf("swap_b\n");
}

void	bottom_to_top_a(t_list **head)
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
	ft_printf("bottom_to_top_a\n");
}

void	bottom_to_top_b(t_list **head)
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
	ft_printf("bottom_to_top_b\n");
}

void	top_to_bottom_a(t_list **head)
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
	ft_printf("top_to_bottom_a\n");
}

void	top_to_bottom_b(t_list **head)
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
	ft_printf("top_to_bottom_b\n");
}

void	top_a_to_top_b(t_list **head_1, t_list **head_2)
{
	t_list *first_a;

	first_a = NULL;
	if (*head_1 == NULL)
		return ;
	first_a = *head_1;
	*head_1 = first_a->next;
	first_a->next = *head_2;
	*head_2 = first_a;
	ft_printf("top_a_to_top_b\n");
}

void	top_b_to_top_a(t_list **head_1, t_list **head_2)
{
	t_list *first_a;

	first_a = NULL;
	if (*head_1 == NULL)
		return ;
	first_a = *head_1;
	*head_1 = first_a->next;
	first_a->next = *head_2;
	*head_2 = first_a;
	ft_printf("top_b_to_top_a\n");
}
