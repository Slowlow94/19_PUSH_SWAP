/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:10 by salowie           #+#    #+#             */
/*   Updated: 2023/08/21 18:28:12 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

t_list *get_moves_list(void)
{
    static t_list *moves = NULL;
    return moves;
}

void	stock_actions(e_op ope)
{
	t_list *moves = get_moves_list();
	t_list *new_node;

	if (moves == NULL)
	{
		moves = ft_lstnew(ope);
		ft_printf("Premier noeud : %d\n", moves->c);
	}
	else
	{
		new_node = ft_lstnew(ope);
		ft_lstadd_back(&moves, new_node);
		ft_printf("noeud suivant : %d\n", ft_lstlast(moves, 0)->c);
	}
}

