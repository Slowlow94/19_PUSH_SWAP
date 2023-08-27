/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:10 by salowie           #+#    #+#             */
/*   Updated: 2023/08/24 13:05:36 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

t_list	**get_moves_list(void)
{
	static t_list	*moves = NULL;

	return (&moves);
}

void	init_moves_list(t_op ope)
{
	t_list	**moves;

	moves = get_moves_list();
	if (!*moves)
		*moves = ft_lstnew_enum(ope);
}

void	stock_actions(t_op ope)
{
	t_list	**moves;
	t_list	*new_node;

	moves = get_moves_list();
	if (!*moves)
		init_moves_list(ope);
	else
	{
		new_node = ft_lstnew_enum(ope);
		ft_lstadd_back(moves, new_node);
	}
}

void	sort_opti(t_list **move_list)
{
	t_list	*move;

	move = NULL;
	move = *move_list;
	give_position_opti(move_list);
	while (move && move->next)
	{
		if ((move->ope == 1 && move->next->ope == 2)
			|| (move->ope == 2 && move->next->ope == 1))
			replace_move(move_list, move->pos, ss);
		if ((move->ope == 4 && move->next->ope == 5)
			|| (move->ope == 5 && move->next->ope == 4))
			replace_move(move_list, move->pos, rr);
		if ((move->ope == 7 && move->next->ope == 8)
			|| (move->ope == 8 && move->next->ope == 7))
			replace_move(move_list, move->pos, rrr);
		move = move->next;
	}
}

void	replace_move(t_list **move_list, int pos, t_op ope)
{
	t_list	*move;

	move = NULL;
	move = *move_list;
	while (move && move->pos != pos)
		move = move->next;
	move->ope = ope;
	deleteone(&(move->next));
	give_position_opti(move_list);
}
