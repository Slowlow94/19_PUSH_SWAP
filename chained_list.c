/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:46:08 by salowie           #+#    #+#             */
/*   Updated: 2023/08/28 19:31:49 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCS/push_swap.h"
#include "INCS/ft_printf.h"

t_list	*ft_lc_new(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->c = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lc_new_enum(t_op ope)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->ope = ope;
	node->next = NULL;
	return (node);
}

t_list	*ft_lc_last(t_list *lst, int i)
{
	int	j;
	int	size;

	if (!lst)
		return (NULL);
	j = 0;
	size = ft_lc_size(lst) - i;
	while (lst->next != NULL && j < (size - 1))
	{
		lst = lst->next;
		j++;
	}
	return (lst);
}

void	ft_lc_add_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lc_last(*lst, 0)->next = new;
}

int	ft_lc_size(t_list *lst)
{
	int		lenght;

	lenght = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lenght++;
		lst = lst->next;
	}
	return (lenght);
}
