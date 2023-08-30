/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:14:28 by Sarah             #+#    #+#             */
/*   Updated: 2023/08/30 13:14:15 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/ft_printf.h"
#include "INCS/push_swap.h"

void	ft_lc_clear(t_list **lst)
{
	t_list	*temp;

	temp = NULL;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
}

void	deleteone(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	free(temp);
}
