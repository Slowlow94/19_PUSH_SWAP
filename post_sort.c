/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:10 by salowie           #+#    #+#             */
/*   Updated: 2023/08/22 12:08:04 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

t_list **get_moves_list(void)
{
    static t_list *moves = NULL;
    return &moves;
}

void init_moves_list(e_op ope)
{
    t_list **moves = get_moves_list();
    if (!*moves)
    {
        *moves = ft_lstnew_enum(ope);
    }
}


void	stock_actions(e_op ope)
{
	t_list **moves = get_moves_list();
	t_list *new_node;

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
	t_list *move;
	move = NULL;
	move = *move_list;
	ft_printf("valeur tete : %d\n", (*move_list)->c);
	give_position_opti(move_list);
	while (move && move->next)
	{
		if ((move->ope == 1 && move->next->ope == 2) 
			|| (move->ope == 2 && move->next->ope == 1))
			replace_move(move_list, move->position, ss);
		if ((move->ope == 4 && move->next->ope == 5) 
			|| (move->ope == 5 && move->next->ope == 4))
		{
			replace_move(move_list, move->position, rr);
		}
		if ((move->ope == 7 && move->next->ope == 8) 
			|| (move->ope == 8 && move->next->ope == 7))
		{
			replace_move(move_list, move->position, rrr);
		}
		move = move->next;
	}
}

void	replace_move(t_list **move_list, int pos, e_op ope)
{
	t_list *move;

	move = NULL;
	move = *move_list;
	while (move && move->position != pos)
		move = move->next;
	move->ope = ope;
	deleteone(&(move->next));
	give_position_opti(move_list);
}

void	give_position_opti(t_list **head)
{
	int	i;
	t_list *a;

	a = NULL;
	a = *head;
	i = 0;
	while (a)
	{
		a->position = i;
		i++;
		a = a->next;
	}
}
void	print_action_list(t_list **move_list)
{
	const char* op_names[] = {
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
}
