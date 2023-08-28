/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:04:25 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/28 13:20:11 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

void	give_position_opti(t_list **head)
{
	int		i;
	t_list	*a;

	a = NULL;
	a = *head;
	i = 0;
	while (a)
	{
		a->pos = i;
		i++;
		a = a->next;
	}
}

void	print_action_list(t_list **move_list)
{
	const char	*op_names[] = {
		"op_NULL",
		"sa",
		"sb",
		"ss",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
		"pa",
		"pb" };

	while (*move_list && (*move_list)->next)
	{
		ft_printf("%s\n", op_names[(*move_list)->ope]);
		move_list = &(*move_list)->next;
	}
	if (*move_list && (*move_list)->next == NULL)
		ft_printf("%s\n", op_names[(*move_list)->ope]);
}
