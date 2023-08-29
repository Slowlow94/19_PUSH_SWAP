
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:10 by salowie           #+#    #+#             */
/*   Updated: 2023/08/29 15:03:34 by salowie          ###   ########.fr       */
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
		*moves = ft_lc_new_enum(ope);
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
		new_node = ft_lc_new_enum(ope);
		ft_lc_add_back(moves, new_node);
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
			replace_move(&move, move->pos, ss);
		if ((move->ope == 4 && move->next->ope == 5)
			|| (move->ope == 5 && move->next->ope == 4))
			replace_move(&move, move->pos, rr);
		if ((move->ope == 7 && move->next->ope == 8)
			|| (move->ope == 8 && move->next->ope == 7))
			replace_move(&move, move->pos, rrr);
		move = move->next;
	}
}

void	replace_move(t_list **move_list, int pos, t_op ope)
{
	while (*move_list && (*move_list)->pos != pos)
		*move_list = (*move_list)->next;
	(*move_list)->ope = ope;
	deleteone(&((*move_list)->next));
	give_position_opti(move_list);
}
