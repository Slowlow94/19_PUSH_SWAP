/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:43:08 by salowie           #+#    #+#             */
/*   Updated: 2023/08/17 16:39:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	wich_sort(t_list **head_a, t_list **head_b)
{
	int size;

	size = ft_lstsize(*head_a);
	if (size == 3)
		sort_3(head_a);
	else if (size > 3 && size <= 5)
		sort_5(head_a, head_b);
	else
		sort_big(head_a, head_b);
}

void	sort_3(t_list **head_a)
{
	t_list *t;
	t_list *m;
	t_list *b;

	t = *head_a;
	m = (*head_a)->next;
	b = ft_lstlast(*head_a, 0);
	if ((t->c > m->c) && (t->c < b->c) && (m->c < b->c))
		swap_a(head_a);
	if ((t->c > m->c) && (m->c > b->c) && (b->c < t->c))
	{
		top_to_bottom_a(head_a);
		swap_a(head_a);
	}
	if ((t->c > m->c) && (m->c < b->c) && (b->c < t->c))
		top_to_bottom_a(head_a);
	if ((t->c < m->c) && (m->c > b->c) && (b->c > t->c))
	{
		bottom_to_top_a(head_a);
		swap_a(head_a);
	}
	if ((t->c < m->c) && (m->c > t->c) && (b->c < t->c))
		bottom_to_top_a(head_a);
}

int	is_min_on_top(t_list **head_a)
{
	int  min;
	t_list *first;

	first = NULL;
	first = *head_a;
	min = (*head_a)->c;
	while (first != NULL)
	{
		if (min > first->c)
			return (1);
		first = first->next;
	}
	return (0);
}

int	is_min_on_bottom(t_list **head_a)
{
	t_list *last;
	t_list *first;

	first = NULL;
	last = NULL;
	first = *head_a;
	last = ft_lstlast(*head_a, 0);
	while (first != NULL)
	{
		if (first->c < last->c)
			return (1);
		first = first->next;
	}
	return (0);
}

void	sort_5(t_list **head_a, t_list **head_b)
{
	while (ft_lstsize(*head_a) > 3)
	{
		if (is_min_on_top(head_a) == 0)
			top_a_to_top_b(head_a, head_b);
		else if (is_min_on_bottom(head_a) == 0)
		{
			bottom_to_top_a(head_a);
			top_a_to_top_b(head_a, head_b);
		}
		else
			top_to_bottom_a(head_a);
	}
	sort_3(head_a);
	while ((*head_b != NULL))
	{
		if (is_min_on_top(head_b) == 0 && (*head_b)->next != NULL)
			top_to_bottom_b(head_b);
		else
			top_b_to_top_a(head_b, head_a);
	}
}

